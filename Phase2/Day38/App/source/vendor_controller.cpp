#include "./../include/vendor_controller.h"
#include <iostream>

VendorController::VendorController(std::unique_ptr<IVendorRepo> repo) : repo(std::move(repo)) { }

void VendorController::Create() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Vendor Management > Create Vendor" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    Vendor newVendor;
    view.Create(newVendor); 
    repo->Create(newVendor);
    std::cout << "Vendor created successfully." << std::endl;
    std::cout << "Press any key to continue..." << std::endl; std::cin.get();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void VendorController::DisplayOne() { 
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Vendor Management > View Vendor" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    identity_t id;
    std::cout << "Enter id to find:"; std::cin >> id;
    try {
        auto&& vendor = repo->ReadById(id);
        view.DisplayOne(vendor);
    } catch(...) {
        std::cout << "vendor not found." << std::endl;
    }

    std::cout << "Press any key to continue..." << std::endl; std::cin.get();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void VendorController::DisplayAll() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Vendor Management > View Vendor" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    
    std::vector<Vendor> vendors = repo->ReadAll();
    view.DisplayAll(vendors);
    
    std::cout << "Press any key to continue..." << std::endl; std::cin.get();
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}
