#include<iostream>
using namespace std;
bool divisibleByThree(int number){
  int number;
  if(number%3==0)
     return true;
  else 
      return false;
}
void divisibleByThreeTest(){
    int number;
    bool result=false;
    cout<<"Enter a Number to be checked : ";
    cin>>number;
    result=divisibleByThree(number);
    if(result)
        cout<<number<< " is divisible by three";
    else
        cout<<number<< " is not divisible by three";
}
int main(){
     divisibleByThreeTest();
     return 0;
}
