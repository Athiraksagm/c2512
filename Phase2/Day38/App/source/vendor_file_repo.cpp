#include "./../include/vendor_file_repo.h"
#include <iostream>
#include <fstream>
static const std::string repo_file_name = "vendor.dat";
static void CreateFile_() { 
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
    output.close();
}
static identity_t GetLastId_() {
    CreateFile_(); //create file if not exists

    std::fstream file(repo_file_name, std::ios::binary | std::ios::in);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    // Get the size of the file
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();

    // Check if the file is empty
    if (fileSize == 0) {
        file.close();
        return 0; // No records exist
    }

    // Calculate the position of the last record
    size_t lastRecordPos = fileSize - sizeof(FileVendor);

    // Seek to the last record
    file.seekg(lastRecordPos, std::ios::beg);

    // Read the last record
    FileVendor fileVendor;
    file.read((char*)&fileVendor, sizeof(FileVendor));

    file.close();
    return fileVendor.id;
}



void VendorFileRepo::Create(Vendor& entity) { 
    identity_t lastId = GetLastId_();
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    FileVendor fileAccount = VendorConverter::ConvertVendorToFileVendor(entity);
    fileAccount.id = lastId + 1; // new Id
    output.write((char*)&fileAccount, sizeof(fileAccount));
    output.close();
}

Vendor VendorFileRepo::ReadById(identity_t id) {
    CreateFile_(); //create file if not exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    FileVendor fileVendor;

    while (input.read((char*)&fileVendor, sizeof(FileVendor))) {
        if (fileVendor.id == id) {
            input.close();
            return VendorConverter::ConvertFileVendorToVendor(fileVendor);
        }
    }

    input.close();
    throw std::runtime_error("Vendor with given ID not found.");
}

std::vector<Vendor> VendorFileRepo::ReadAll() {
    CreateFile_(); //create file if not exists
    
    std::vector<Vendor> vendors;

    std::ifstream file(repo_file_name, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    FileVendor fileVendor;

    while (file.read((char*)&fileVendor, sizeof(FileVendor))) {
        auto&& vendor = VendorConverter::ConvertFileVendorToVendor(fileVendor);
        vendors.push_back(vendor);
    }

    file.close();
    return vendors;
}
