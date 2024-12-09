#include<iostream>
#include<exception>
#include<vector>
using namespace std;

class DivideByZeroException : public exception
{
    public:
        const char* what() const noexcept override
        {
            return "Division by zero";
        }
};

int findGCD(int a, int b) {
    if(b == 0) {
        //throw "Division by zero";//1
        throw DivideByZeroException();
    }
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main()
{
    
    vector<int> nums = {0, 2, 1, 5, 4};//{1, 2, 1, 5, 4} //{0, 2, 1, 5, 4}

    try
    {
        int x = nums.at(1);
        int y = nums.at(0);
        cout << x << endl;
        cout << y << endl;

        int gcd = findGCD(x, y);
        cout << gcd << endl;

        cout << nums.at(6) << endl;
    }
    catch(const out_of_range& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    /*catch(const char* e)//2
    {
        cout << "Exception: " << e << endl;
    }*/
    catch(const DivideByZeroException& e)
    {
        cout << "Exception(UE): " << e.what() << endl;
    }
    /*catch(const exception& e)
    {
        cout << "Exception(UE): " << e.what() << endl;
    }*/
    catch(...)
    {
        cout << "Unknown Exception" << endl;
    }
    cout << "Program Continues..." << endl;
    return 0;
}
