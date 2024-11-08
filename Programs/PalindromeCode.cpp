#include<iostream>
#include<string>
using std::cout;
using std::cin;

bool palindromeOrNot(string str)
{
  string str;
  string temp;
  int i = 0, j;
  temp = str;
  j = str.length()-1;
  
  while(i<j)
   {
      swap(str[i], str[j]);
      i++;
      j--;
   }
  
  if(temp == str)
  {
      return true;
  }
  else 
  {
      return false;
  }
}

void palindromeOrNotTest(void)
{
    string str;
    bool result = false;
  
    cout << "Enter a string to be checked : ";
    cin >> str;
  
    result = palindromeOrNot(str);
    if(result)
    {
        cout<<str<< " is a Palindrome ";
    }
    else
    {
        cout << str << " is not a Palindrome ";
    }
}

int main()
{
     palindromeOrNotTest();
     return 0;
}







    
