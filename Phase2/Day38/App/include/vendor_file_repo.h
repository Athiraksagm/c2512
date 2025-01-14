#pragma once
#include "ivendor_repo.h"
#include "vendor.h"
#include "type.h"

class VendorFileRepo : public IVendorRepo
{
    public: 
        void Create(Vendor& entity) override;
        Vendor ReadById(identity_t id) override;
        std::vector<Vendor> ReadAll() override;
};
