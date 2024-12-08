1. Write a program to read 10 numbers from the user, find their sum. [with array]
2. Write a program to read 10 numbers from the user, find their sum [without using arra
[pseudo code and c++ code]

Answer - 1
  
`````````````````````````````````````````````````````````
    pseudo code 
`````````````````````````````````````````````````````````
function readNumbers(numbers -> [long], size -> int)
    for I in 0..(size-1):
        input number 
        numbers[I] = numbr 
    end for 

function findSum(numbers -> [long], size -> int) -> long 
    sum = 0
    
    for I in 0..(size-1):
        sum += numbers[I]
    end for 

    return sum 

function findSumTest():
    size = 10
    //declare x[size] -> long
    readNumbers(x, size)
    sum = findSum(x, size)
    print sum 

pseudo main:
    findSumTest()

`````````````````````````````````````````````````````````
    C++ 
`````````````````````````````````````````````````````````
#include<cstdlib>
#include<iostream>
#define MAX_SIZE 10

using std::cin;
using std::cout;

void readNumbers(long numbers[], int size)
{
    for(int I = 0; I < size; I++)
    {
        long number {0L};

        cout << "Enter number at index " << I << ":"; 
        cin >> number; 

        numbers[I] = number; 
    } 
}

long findSum(long numbers[], int size)
{  
    long sum {0L};
    
    for(int I = 0; I < size; I++)
    {
        sum += numbers[I];
    } 

    return sum;
}

void findSumTest()
{
    int size = MAX_SIZE;
    long x[size] {};

    readNumbers(x, size);

    long sum = findSum(x, size);

    cout << "Sum is " << sum; //<iostream>, cin, cout 
}

int main()
{
    findSumTest();

    return EXIT_SUCCESS; //<cstdlib>
}
`````````````````````````````````````````````````````````
