single inheritance using static binding:
=============================================================
Create two static objects for Both Base and Derived class
and call all behaviours
and 
one two dynamic objects for Base and Derived class 
and call all behaviours

Define constructors and destructors for all the classes 

Problem 15: `Sports Management`
- Create a base class `Player` with fields `name` and `age`, and a behavior `train()`.
- Derive a class `CricketPlayer` with fields `battingAverage` and a behavior `playMatch()`.

solution:

#include <iostream>
#include <string>

using namespace std;

// Base class
class Player
{
private:
    string name;
    int age;

public:
    // Constructor
    Player(const string& playerName, int playerAge) : name(playerName), age(playerAge) 
    {
        cout << "Player constructor called for " << name << endl;
    }

    // Destructor
    virtual ~Player()
    {
        cout << "Player destructor called for " << name << endl;
    }

    // Behavior
    void train()
    {
        cout << name << " is training at the age of " << age << "." << endl;
    }
};

// Derived class
class CricketPlayer : public Player 
{
private:
    double battingAverage;

public:
    // Constructor
    CricketPlayer(const string& playerName, int playerAge, double average) 
        : Player(playerName, playerAge), battingAverage(average)
    {
        cout << "CricketPlayer constructor called for " << name << endl;
    }

    // Destructor
    ~CricketPlayer() 
    {
        cout << "CricketPlayer destructor called for " << name << endl;
    }

    // Behavior
    void playMatch()
    {
        cout << name << " is playing a match with a batting average of " << battingAverage << "." << endl;
    }
};

int main()
 {
    // Static objects
    cout << "=== Static object ===" << endl;
    Player staticPlayer("Rahul", 25);
    CricketPlayer staticCricketPlayer("Adarsh", 28, 55.3);

    staticPlayer.train();
    staticCricketPlayer.train();
    staticCricketPlayer.playMatch();

    // Dynamic objects
    cout << "\n=== Dynamic object ===" << endl;
    Player* dynamicPlayer = new Player("Athira", 23);
    Player* dynamicCricketPlayer = new CricketPlayer("Aish", 30, 45.7);

    dynamicPlayer->train();
    dynamicCricketPlayer->train();
    // Need typecasting to call derived-specific methods
    dynamic_cast<CricketPlayer*>(dynamicCricketPlayer)->playMatch();

    // Clean up dynamic objects
    delete dynamicPlayer;
    delete dynamicCricketPlayer;

    return 0;
}

