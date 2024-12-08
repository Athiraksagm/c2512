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
