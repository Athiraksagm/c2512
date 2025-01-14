#include <cstring>
#include "vendor.h"
FileVendor VendorConverter::ConvertVendorToFileVendor(Vendor& vendor) {
    FileVendor fileVendor;
    fileVendor.id = vendor.GetId();
    strcpy(fileVendor.name, vendor.GetName().c_str());
    fileVendor.ratings = vendor.GetRatings();
    return fileVendor;
}

Vendor VendorConverter::ConvertFileVendorToVendor(FileVendor& fileVendor) {
    Vendor vendor;
    vendor.SetId(fileVendor.id);
    vendor.SetName(fileVendor.name);
    vendor.SetRatings(fileVendor.ratings);
    return vendor;
}
