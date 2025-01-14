#include<iostream>
#include<memory>
#include "./../include/vendor_file_repo.h"
#include "./../include/vendor_controller.h"
#include "./../include/vendor_main.h"

VendorMenuOption ReadVendorMenu() {
    int choice;

    std::cout << "------------------------------------------- " << std::endl;
    std::cout << "Vendor Management" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << ((int)VendorMenuOption::Create)     << " - Create Vendor" << std::endl;
    std::cout << ((int)VendorMenuOption::View)       << " - View Vendor" << std::endl;
    std::cout << ((int)VendorMenuOption::DisplayAll) << " - Display All Vendor" << std::endl;
    std::cout << ((int)VendorMenuOption::Exit)       << " - Go Back" << std::endl;
    std::cout << "Your choice:"; std::cin >> choice;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    return (VendorMenuOption)choice;
}

void ManageVendor() { 
    std::unique_ptr<VendorFileRepo> repo = std::make_unique<VendorFileRepo>();
    VendorController controller(std::move(repo));
    VendorMenuOption choice;

    do { 
        choice = ReadVendorMenu();
        switch(choice) {
            case VendorMenuOption::Create:
                {
                    controller.Create();
                } break;
            case VendorMenuOption::View:
                {
                    controller.DisplayOne();
                } break;
            case VendorMenuOption::DisplayAll:
                {
                    controller.DisplayAll();
                } break;
            case VendorMenuOption::Exit:
                {

                } break;
        }
    } while(VendorMenuOption::Exit != choice);
}
