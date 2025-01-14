#pragma once
#include "vendor_ui.h"
#include "ivendor_repo.h"
#include <memory>
class VendorController {
    private: 
        VendorUI view;
        std::unique_ptr<IVendorRepo> repo;
    public:  
        void Create();
        void DisplayOne();
        void DisplayAll();

        VendorController(std::unique_ptr<IVendorRepo> repo);
};
