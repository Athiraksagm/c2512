Examples for diamond problem in inheritance:
=============================================================
These class structures represent the diamond problem,
where the `final derived class` 
inherits ambiguously 
from two intermediate classes 
that share a common base class.
=============================================================
Create one static object for final-derived class
and call all behaviours
and 
one dynamic object for final-derived class 
and call all behaviours

Define constructors and destructors for all the classes 

Question 15: `Home Automation`
- `Base Class:` Device `{field: brand, behavior: connect()}`
- `Derived Class 1:` LightingSystem `{field: color, behavior: adjustBrightness()}`
- `Derived Class 2:` ClimateControl `{field: temperature, behavior: setTemperature()}`
- `Final Derived Class:` SmartHomeHub `{field: integrationCount, behavior: automate()}`

Solution:

#include <iostream>
#include <string>
using namespace std;

// Base class Device
class Device {

private:
     string brand;

public:
    // Constructor of Device
   Device(const string& b) : brand(b)  
    {
       cout << "Device constructor called for brand: " << brand << endl;
    }

    // Virtual destructor of Bird (important for polymorphic deletion)
    virtual ~Device() 
    {
        cout << "Device destructor called for brand: " << brand << endl;
    }

    // Virtual function for brand
     void connect() 
       {
        cout << "Device (" << brand << ") is now connected." << endl;
       }
};

// Derived class LightingSystem
class LightingSystem: virtual public Device
{
private:
     string color;

public:
    // Constructor of  LightingSystem (calls the constructor of Device)
   LightingSystem(const string& b, const string& c) : Device(b), color(c) 
    {
        cout << "LightingSystem constructor called with color: " << color << endl;
    }

    // Destructor of LightingSystem (calls the constructor of Device)
    ~LightingSystem() 
    {
        cout << "LightingSystem destructor called." << endl;
    }

    // Override Sound function for Crow
   void adjustBrightness()
   {
        cout << "Adjusting brightness for color: " << color << endl;
    }
};

class ClimateControl : virtual public Device {
private:
    int temperature;

public:
    ClimateControl(const string& b, int temp) : Device(b), temperature(temp) {
        cout << "ClimateControl constructor called with temperature: " << temperature << endl;
    }
    ~ClimateControl() {
        cout << "ClimateControl destructor called." << endl;
    }
    void setTemperature() {
        cout << "Setting temperature to: " << temperature << " degrees." << endl;
    }
};

class SmartHomeHub : public LightingSystem, public ClimateControl {
private:
    int integrationCount;

public:
    SmartHomeHub(const string& b, const string& c, int temp, int count)
        : Device(b), LightingSystem(b, c), ClimateControl(b, temp), integrationCount(count) {
        cout << "SmartHomeHub constructor called with integration count: " << integrationCount << endl;
    }
    ~SmartHomeHub() {
        cout << "SmartHomeHub destructor called." << endl;
    }
    void automate() {
        cout << "Automating " << integrationCount << " devices." << endl;
    }
};


int main() {
    cout << "Creating static object:" << endl;
    SmartHomeHub staticHub("BrandX", "Warm White", 24, 5);
    staticHub.connect();
    staticHub.adjustBrightness();
    staticHub.setTemperature();
    staticHub.automate();

    cout << "\nCreating dynamic object:" << endl;
    SmartHomeHub* dynamicHub = new SmartHomeHub("BrandY", "Cool Blue", 22, 3);
    dynamicHub->connect();
    dynamicHub->adjustBrightness();
    dynamicHub->setTemperature();
    dynamicHub->automate();
    delete dynamicHub;

    return 0;
}

