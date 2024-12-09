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

protected:
     string brand;

public:
    // Constructor of Device
   Device(const string& b) : brand(b)  
    {
       cout << "Device constructor called ! " << endl;
    }

    // Virtual destructor 
    virtual ~Device() 
    {
        cout << "Device destructor called !" << endl;
    }

    // Behavior
     void connect() 
       {
        cout << "Device " << brand << " is now connected." << endl;
       }
};

// Derived class LightingSystem
class LightingSystem: virtual public Device
{
protected:
     string color;

public:
    // Constructor of  LightingSystem (calls the constructor of Device)
   LightingSystem(const string& b , const string& c) : Device(b), color(c) 
    {
        cout << "LightingSystem constructor called ! "  << endl;
    }

    // Destructor of LightingSystem (calls the constructor of Device)
    ~LightingSystem() 
    {
        cout << "LightingSystem destructor called !" << endl;
    }

    // behavior
   void adjustBrightness()
   {
        cout << "Adjusting brightness for color: " << color << endl;
    }
};

class ClimateControl : virtual public Device {
protected:
    int temperature;

public:
    //constructor
    ClimateControl(const string& b, int temp) : Device(b), temperature(temp)
    {
        cout << "ClimateControl constructor called ! " << endl;
    }
    //destructor
    ~ClimateControl()
    {
        cout << "ClimateControl destructor called." << endl;
    
    }
    //behavior
    void setTemperature() 
    {
        cout << "Setting temperature to: " << temperature << " degrees." << endl;
    }
};

class SmartHomeHub : public LightingSystem, public ClimateControl {
protected:
    int integrationCount;

public:
    //constructor
    SmartHomeHub(const string& b, const string& c, int temp, int count)
        : Device(b), LightingSystem(b, c), ClimateControl(b, temp), integrationCount(count) 
    {
        cout << "SmartHomeHub constructor called! "  << endl;
    }
    //destructor
    ~SmartHomeHub()
    {
        cout << "SmartHomeHub destructor called." << endl;
    }
    //behavior
    void automate()
    {
        cout << "Automating " << integrationCount << " devices." << endl;
    }
};


int main() {
    cout << "Creating static object:" << endl;
    SmartHomeHub sh1("BrandX", "Warm White", 24, 5);
    sh1.connect();
    sh1.adjustBrightness();
    sh1.setTemperature();
    sh1.automate();

    cout << "\nCreating dynamic object:" << endl;
    SmartHomeHub* sh2 = new SmartHomeHub("BrandY", "Cool Blue", 22, 3);
    sh2->connect();
    sh2->adjustBrightness();
    sh2->setTemperature();
    sh2->automate();
    delete sh2;

    return 0;
}

