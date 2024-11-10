#include<iostream>
using std::cout;
using std::cout;

bool perfectNumber(int number)
{
 int divisor;
 int sum = 0;
 
 for (int i = 1; i < number; i++)
 {
    divisor = (number % i);
    if (divisor == 0)
      sum = (sum + i);
 }
if (sum == number)
{
    return true;
}
else
{
    return false;
}
}

void perfectNumberTest(void)
{
 int number;
 bool result = false;
 
 cout << " Enter the number to be checked : ";
 cin >> number;
 
 result = perfectNumber(number);
 if (result)
 {
      cout << number << "is a perfect number ";
 }
 else
 {
      cout << number << "is not a perfect number ";
 }
}

int main(void)
{
 perfectNumberTest();
 return 0;
}

