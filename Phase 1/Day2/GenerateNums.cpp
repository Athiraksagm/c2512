#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 6;

int giveMeNumber()
{	
    return rand() % MAX_SIZE + 1;
}

bool isExist(int nums[], int size, int num)
{
    for(int i = 0; i < size; i++) // Loop from 0 to size - 1
    {
        if(nums[i] == num){
            return true;
        }
    }
    return false; 
}

void giveMeNumbers(int nums[])
{
    for(int i = 0; i < MAX_SIZE; i++)
    {
        int num = giveMeNumber();
        while(isExist(nums, i, num)) // Check for existing numbers
        {
            num = giveMeNumber();
        }
        nums[i] = num; // Assign the unique number
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // Seed the RNG
    int numbers[MAX_SIZE];
    giveMeNumbers(numbers);

    for(int i = 0; i < MAX_SIZE; i++) // Loop from 0 to MAX_SIZE - 1
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}

