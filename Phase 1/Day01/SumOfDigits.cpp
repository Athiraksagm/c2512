#include <iostream>
using namespace std;
int findSumOfDigits(int number) //author/owner 
{
    int firstDigit = number / 10;
    int secondDigit = number % 10;
    int sum = firstDigit + secondDigit;
    return sum;
}

void findSumOfDigitsTest() //user of findSumOfDigits
{
    int number;
    cout << "Enter a number:";
    cin >> number;
    
    int sum = findSumOfDigits(number);
    
    cout << "The sum is " << sum << endl;
}

int main()
{
    
    findSumOfDigitsTest();

    return 0;
}
