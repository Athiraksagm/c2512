#pragma once
#include "type.h"
#include <string>
class Vendor {
    private:
        identity_t id;
        std::string name;
        short int ratings;
    public: // getters | setters 
        void SetId(identity_t id) { this->id = id; }
        identity_t GetId() { return this->id; }
        void SetName(std::string name) { this->name = name; }
        std::string GetName() { return this->name; }
        void SetRatings(short int ratings) { this->ratings = ratings; }
        short int GetRatings() { return this->ratings; }
};

class FileVendor {
    public: 
        identity_t id;
        char name[255];
        short int ratings;
};

class VendorConverter { 
    public: 
        static FileVendor ConvertVendorToFileVendor(Vendor& vendor);
        static Vendor ConvertFileVendorToVendor(FileVendor& fileVendor);
};
