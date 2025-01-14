#include "./../include/vendor_ui.h"
#include <iostream>
static void Read(std::string& name, short int& ratings, int flags = 3) {
    if((flags & 1) != 0) {
        std::cout << "Name:"; std::cin >> name;
    }
    if((flags & 2) != 0) {
        std::cout << "ratings:"; std::cin >> ratings;
    }
}

void VendorUI::Create(Vendor& vendor) {
    std::string name;
    short int ratings;
    int flags = 3;
    do {
        Read(name, ratings, flags);
        int proceedOption; 
        
        std::cout << "1 - edit `name`." << std::endl; 
        std::cout << "2 - edit `ratings`." << std::endl; 
        std::cout << "3 - edit `name and ratings`." << std::endl; 
        std::cout << "4 - I am sure to create." << std::endl;
        std::cout << "\tYour choice:"; std::cin >> proceedOption;

        if(4 == proceedOption) {
            vendor.SetName(name);
            vendor.SetRatings(ratings);
            break;
        }
        flags = proceedOption;
    } while(true);
}
void VendorUI::DisplayOne(Vendor& vendor) {
    std::cout << "id:" << vendor.GetId() << std::endl;
    std::cout << "name:" << vendor.GetName() << std::endl;
    std::cout << "ratings:" << vendor.GetRatings() << std::endl;
}
void VendorUI::DisplayAll(std::vector<Vendor>& vendors) {
    std::cout << "````````````````````````````````````````````" << std::endl;
    std::cout << "id\tname\tratings" << std::endl;
    std::cout << "````````````````````````````````````````````" << std::endl;
    
    for(auto vendor : vendors) {
        std::cout << vendor.GetId() << "\t" 
                  << vendor.GetName() << "\t"
                  << vendor.GetRatings() << std::endl;    
    }

    if(vendors.size() == 0) {
        std::cout << "No vendors found." << std::endl;
    }


    std::cout << "````````````````````````````````````````````" << std::endl;
}
