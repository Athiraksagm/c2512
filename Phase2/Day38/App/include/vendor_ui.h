#pragma once
#include "vendor.h"
#include <vector>
class VendorUI {
    public:
        void Create(Vendor& vendor);
        void DisplayOne(Vendor& vendor);
        void DisplayAll(std::vector<Vendor>& vendors);
};
