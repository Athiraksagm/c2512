#include <iostream>
using std::cout;
using std::cin;

int findSumOfDigits(int number)  
{
    int firstDigit = (number / 10);
    int secondDigit = (number % 10);
    int sum = (firstDigit + secondDigit);
    return sum;
}

void findSumOfDigitsTest() 
{
    int number;
  
    cout << "Enter a number: ";
    cin >> number;
    
    int sum = findSumOfDigits(number);
    
    cout << "The sum is :  " << sum << endl;
}

int main()
{
    
    findSumOfDigitsTest();

    return 0;
}
