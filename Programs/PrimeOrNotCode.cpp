#include<iostream>
using std::cout;
using std::cin;

bool primeOrNot(int number)
{
 for(int i=1;i< number/2;i++)
 {
    if(number % i == 0)     
      {
      return true;
      }
    else
      {
      return false;
      }
  }
}

void primeOrNotTest(void)
{
 int number;
 bool result = false;

 cout << " Enter the number to be checked : ";
 cin >> number;

 result = primeOrNot(number);
 if(result)
     {
      cout << number << "is a prime number ";
     }
 else
     {
      cout << number << "is not a prime number ";
     }
}

int main(void)
{
 primeOrNotTest();
 return 0;
}
