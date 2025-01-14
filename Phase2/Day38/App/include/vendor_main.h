#pragma once

enum class VendorMenuOption {
    Create = 1,
    View = 2,
    DisplayAll = 3,
    Exit = 4
};

VendorMenuOption ReadVendorMenu();
void ManageVendor();
