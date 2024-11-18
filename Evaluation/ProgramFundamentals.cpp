------------------------------------------------Question 1------------------------------------------
//To find average of two numbers
//pseudocode

pseudofunctions:

function findAverage(number1, number2) -> int
	average = (number1 + number2) / 2
    	return average

function findAverageTest()
    	input number1, number2
    	result = findAverage(number1, number2)
    	print result
    	
end functions

pseudocode:

findAverageTest()

//C++ code

#include <iostream>
using std::cout;
using std::cin;

int findAverage(int number1,int number2)
{
    int average;
    
    average = (number1 + number2)/ 2;
    
    return average;
}

void findAverageTest(void)
{
    int number1, number2, result;
    
    cout << "Enter the numbers: ";
    cin >> number1;
    cin >> number2;
    
    result = findAverage(number1, number2);
    cout << "The average is: " << result << endl;
}

int main()
{
    findAverageTest(void);
    
    return 0;
}


-------------------------------------------------Question 2--------------------------------------
//To find cube of number
//pseudocode

pseudofunction:

function calculateCube(number -> int) -> int
	return number * number * number
  
function calculateCubeTest()
    	input number
    	result = calculateCube(number)
    	print result
    	
End function

pseudocode:

calculateCubeTest()


  //C++ code

#include <iostream>
using std::cout;
using std::cin;

int calculateCube(int number)
{
    return number * number * number;
}

void calculateCubeTest(void)
{
    int number,result;

    cout << "Enter a number: ";
    cin >> number;

    result = calculateCube(number);
    cout << "The cube of the number is: "<< result << endl;
}

int main(void)
{
    calculateCubeTest();

    return 0;
}

------------------------------------------------Question 3------------------------------------------
// to find square of the number.
// pseudo code
pseudofunction:

findSquare(number -> int) -> int
	return number * number

findSquareTest() 
	input number
	square = findSquare(number)
	print square

findSquareTest()

// c++ code
#include <iostream>
using namespace std;

int findSquare(int number) {
    return number * number;
}

void findSquareTest() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int square = findSquare(number);

    cout << "Square is: " << square << endl;
}

int main() {
    findSquareTest(); 
    return 0;
}



------------------------------------------------Question 4------------------------------------------
// swap two numbers. 
// pseudo code

pseudofunction:
function swapNums(&number1,&number2)
	temp = number1
	number1 = number2
	number2 = temp
	
function swapNumsTest()
	input number1,number2
	swapNums(number1,number2)
	print number1,number2

swapNumsTest()

// c++ code
#include <iostream>
using namespace std;

void swapNums(int &num1,int &num2){
    int temp=num1;
    num1=num2;
    num2=temp;
}

void swapNumsTest(){
    int num1,num2;
    cout << "Enter number 1:";
    cin >> num1;
    cout << "Enter number 2:";
    cin >> num2;
    swapNums(num1,num2);
    cout << "Number 1:" << num1;
    cout << "\nNumber 2:" << num2;
}


int main()
{
    swapNumsTest();

    return 0;
}



---------------------------------------------Question 5-------------------------------------------
to check the number is divisible by 3
// pseudo code
function isDivisibleBy3(number)
    return (number % 3 == 0)
end function

function isDivisibleBy3Test()
    input number

    result = isDivisibleBy3(number)

    if result
        print "The number", number, "is divisible by 3."
    else
        print "The number", number, "is not divisible by 3."
    end if
end function

start
   isDivisibleBy3Test()
end


// c++ code

#include<iostream>
#include<cstdlib>
using std::cout;
using std::cin;
using std::endl;

bool isDivisibleBy3(int number) 
{
    return (number % 3 == 0);
}

void isDivisibleBy3Test(void) 
{
    int number;
    cout << "Enter the number : ";
    cin >> number;

    bool result = isDivisibleBy3(number);

    if (result) 
    {
        cout << "The number " << number << " is divisible by 3." << endl;
    } 
    else 
    {
        cout << "The number " << number << " is not divisible by 3." << endl;
    }
}

int main() 
{
    isDivisibleBy3Test();

    return EXIT_SUCCESS;
}


------------------------------------------------------Question 6-----------------------------------------------

//Check a number is divisible by 27 or not

Pseudo functions:

function isDivisibleByTwentySeven(number->int)->bool

    if (number MOD 27 == 0)
        return true
    endif

    return false
	
function isDivisibleByTwentySevenTest()
    input number

    result=isDivisibleByTwentySeven(number)
	
    if result
        print"The number is divisible by 27"
    else
        print"The number is not divisible by 27"

Pseudocode:

isDivisibleByTwentySevenTest()

CODE:

#include<iostream>
using std::cout;
using std::cin;

bool isDivisibleByTwentySeven(int number)
{
    if(number % 27 == 0)
    {
        return true;
    }
    
    return false;
}

void isDivisibleByTwentySevenTest(void)
{
    int number;
	
    cout<< "Enter a Number:";
    cin>> number;
	
    int result=isDivisibleByTwentySeven(number);
    
    if(result)
    {
        cout<< "The number is divisible by 27";
    }
    else
    {
        cout<< "The number is not divisible by 27";
    }
}

int main(void)
{
    isDivisibleByTwentySevenTest();
	
    return 0;
}

------------------------------------------------------Question 7---------------------------------------------------

//To print N natural numbers

//pseudocode

pseudo functions:

function printNaturalNumbers(n->int)->int
    	for i = 1..n
        	print i
    	End for

function printNaturalNUmbersTest()
    	input n
    	printNaturalNumbers(n)
    	
end functions

pseudocode:

printNaturalNUmbersTest()


//C++ code

#include <iostream>
using std::cout;
using std::cin;

void printNaturalNUmbers(int n)
{
    	int i;
    	
    	for(i = 1 ; i <= n ; i++)
    	{
        	cout << i << endl;
        }
}

void printNaturalNUmbersTest(void)
{
    int n;
    
    cout << "Enter number: ";
    cin >> n;
    
    printNaturalNUmbers(n);
}

int main(void)
{
    printNaturalNUmbersTest();
    
    return 0;
}

----------------------------------------------------Question 8----------------------------------------------
//To check a number palindrome

//pseudocode

pseudo functions:

function reverseNumber(number -> int) ->int
	reverse = 0
        while(number != 0)
        	reminder = (number % 10)
              	reverse = ((reverse * 10) + reminder)
              	number = (number / 10)
        end while
	return reverse

function isNumberPalindrome(number -> int) ->bool
         reverse = reverseNumber(number)
         return (number == reverse)

function isNumberPalindromeTest()
         input number
         if(isNumberPalindrome(number))
            print "Number is Palindrome"
         else
             print "Number is not Palindrome"
         end if
         
end functions

pseudo code :

isNumberPalindromeTest()


//c++ code

#include <iostream>
using std::cout;
using std::cin;

int reverseNumber(int number)
{
    int reverse = 0;

    while(number != 0)
    {
        int reminder = (number % 10);
        reverse = ((reverse * 10) + reminder);
        number = (number / 10);
    }
     
    return reverse;
}

bool isNumberPalindrome(int number)
{
    int reverse = reverseNumber(number);

    return (number == reverse);
}
         
void isNumberPalindromeTest(void)
{
    int number;
    
    cout << "Enter number: ";
    cin >> number;
    
    if(isNumberPalindrome(number))
    {
        cout << number << " is Palindrome";
    }
    else
    {
        cout << number << " is not Palindrome";
    }
}

int main(void)
{
    isNumberPalindromeTest();
    
    return 0;
}


------------------------------------------------Question 9------------------------------------------

// to check a number amstrong. 
// pseudo code

pseudo function:

function isArmstrong(number -> int) -> bool
	copyNumber = number
	int counter = 0
	while copyNumber > 0
		copyNumber = copyNumber/10
		counter = counter + 1
	end while
	copyNumber = number
	int sum = 0
	while copyNumber > 0
		temp = copyNumber % 10
		sum = sum + temp^counter
		copyNumber = copyNumber / 10
	end while
	if sum == number
		return true
	return false

function isArmstrongTest(){
	input number
	bool result = isArmStrong(number)
	if result == true
		print "Armstrong"
	else
		print "Not Armstrong"
	end if
}

isArmStrongTest()


// c++ code

#include <iostream>
#include <cmath>
using namespace std;

bool swapNums(int number){
    int copyNumber=number;
    int counter=0;
    while (copyNumber>0){
        copyNumber = copyNumber/10;
		counter = counter + 1;
    }
    copyNumber = number;
	int sum = 0;
	while (copyNumber > 0){
		int temp = copyNumber % 10;
		sum = sum + (int)pow(temp,counter);
		copyNumber = copyNumber / 10;
	}
	if (sum == number){
		return true;
	}
	return false;
}

void isArmstrongTest(){
    int num;
    cout << "Enter number:";
    cin >> num;
    bool result=swapNums(num);
    if (result ==true){
        cout << "Armstrong number";
    }
    else{
        cout << "Not Armstrong";
    }
}

int main()
{
    isArmstrongTest();
    return 0;
}
------------------------------------------------Question 10------------------------------------------

// to check a number prime.
// pseudo code

pseudofunction:

function isPrime(number -> int) -> bool
	if (number < 2)
		return false
	end if

	int squareRoot = sqrt(number)

	for i in (2..squareRoot)
		if (number % i) == 0
			return false
		end if
	end for
	
	return true
	
function isPrimeTest(void) -> void
	input number

	if (isPrime(number))
		print "Number is prime"
	else
		print "Number isn't prime"
	end if

pseudocode:

isPrimeTest()


// c++ code

#include<iostream>
#include<cmath>
using std::cout;
using std::cin;

bool isPrime(int number)
{
	if (number < 2)
	{
		return false;
	}
	
	int squareRoot = (int)sqrt(number);

	for (int i = 2; i <= squareRoot; i ++)
	{
		if ((number % i) == 0)
		{
			return false;
		}
	}
	
	return true;
}
	
void isPrimeTest(void)
{
    int number;
    
	cout << "Enter a number: ";
	cin >> number;

	if (isPrime(number))
	{
		cout << number << " is prime";
	}
	else
	{
		cout << number << " isn't prime";
	}
}

int main(void)
{
    isPrimeTest();
    
    return 0;
}


------------------------------------------------------Question 11--------------------------------------------------

//check a number is perfect or not

Pseudofunctions:

function isPerfectNumber(number->int)->bool
  sum = 0
    
  half = (number / 2)
 	
  for i from 1 ..half
 	if (number % i == 0)
 	    sum = (sum + i)
      endif
  endfor
 	
  return (sum == number)
 	
function isPerfectNumberTest()
 
    input number
 	  bool result = isPerfectNumber(number)
 	
 	  if (result)
 	      print "The number is perfect"
 	  else
 	      print "The number is not perfect"
 	  endif
 	
Pseudocode:

    isPerfectNumberTest()


#include<iostream>
using std::cout;
using std::cin;


bool isPerfectNumber(int number)
{
    int sum = 0;
    
    int half = (number / 2);
 	
 	for (int i = 1 ; i <= half ; i++)
 	{
 	    if (number % i == 0)
 	    {
 	       sum = (sum + i);
 	    }
 	}
 	
 	return (sum == number);
}

void isPerfectNumberTest(void)
{
    int number;
    
    cout << "Enter a number:";
    cin >> number;
    
 	bool result = isPerfectNumber(number);
 	
 	if (result)
 	{
 	    cout << number << " is a perfect number";
 	}
 	else
 	{
 	    cout << number << " is not a perfect number";
 	}
}

int main(void)
{
    isPerfectNumberTest();
 
    return 0;
}
 

--------------------------------------------------------Question 12--------------------------------------------

//check odd or even

Pseudo functions:

function isEven(number->int)->bool
    return (number % 2 == 0) 
	
function isEvenTest()

    input number

    if (isEven(number))
	print "The number is even"
    else
	print "The number is odd"
    endif
	
pseudocode:

isEvenTest()

CODE:

#include<iostream>
using std::cin;
using std::cout;

bool isEven(int number)
{
    return ((number % 2) == 0);
}

void isEvenTest(void)
{
    int number;
    
    cout << "Enter a number:";
    cin >> number;
    
    if (isEven(number))
    {
	cout << number << " is even";
    }
    else
    {
	cout << number << " is odd";
    }
}

int main(void)
{
    isEvenTest();
    
    return 0;
}

-------------------------------------------------------------Question 13-------------------------------------------------

//To check a year leap

//pseudocode

pseudofunctions :

function isLeapYear(year -> int) -> bool
        return ((((year % 4)== 0) && ((year % 100) !=0)) || ((year % 400) == 0)))
           
function isLeapYearTest()
        input year
        if (isLeapYear(year))
           print "Leap Year"
        else
           print "Not Leap Year"
        end if
        
end functions

pseudocode :

isLeapYearTest()


//c++ code

#include <iostream>
using std::cout;
using std::cin;

bool isLeapYear(int year)
{
    return ((((year % 4) == 0) && ((year % 100) !=0)) || ((year % 400) == 0)));
}
        
void isLeapYearTest(void)
{
   int year;
   
   cout << "Enter Year: "; 
   cin >> year;
   
   if (isLeapYear(year))
   {
       cout << year << " is Leap Year";
   }
   else
   {
       cout << year << " Not Leap Year";
   }
}

int main(void)
{
    isLeapYearTest();
    
    return 0;
}

---------------------------------------------------------------Question 14----------------------------------------------------

//To check a number perfect square or not

//pseudocode

pseudo functions:

function isPerfectSquare(number -> int) -> bool
    	root = integer part of sqrt(number)
    	if (root * root == number)
        	return true
        end if
    	return false

function isPerfectSquareTest()
    	input number
    	result = isPerfectSquare(number)
    	if (result == true)
        	print "Entered number is a perfect square"
    	else
        	print "Entered number is not a perfect square"
	end if
	
end functions
        
pseudo code:

isPerfectSquareTest()


//c++ code

#include <iostream>
#include <cmath> 
using std::cout;
using std::cin;
using std::endl;


bool isPerfectSquare(int number) 
{
	int root = (sqrt(number)); 
    
    	return (root * root == number); 
}


void isPerfectSquareTest(void) 
{
    	int number;
    
    	cout << "Enter a number: ";
    	cin >> number;

    	bool result = isPerfectSquare(number);
    	if (result) 
    	{
       		cout << number << " is a perfect square" << endl;
    	} 
    	else 
    	{
        	cout << number << " is not a perfect square" << endl;
    	}
}

int main(void) 
{
    	isPerfectSquareTest(); 
    
    	return 0;
}

------------------------------------------------Question 15------------------------------------------
15. Reverse the number.  
    pseudofunctions:
    function reverseInteger(num -> int) -> int
        reversed = 0

        while num != 0
            digit = num % 10           
            reversed = reversed * 10 + digit 
            num = num / 10             
        end while

        return reversed

    function reverseIntegerTest(void) -> void
        print "Enter an integer:"
        input num

        reversedNum = call reverseInteger(num)

        print "Reversed Integer: " reversedNum

    pseudocode:
        reverseIntegerTest(void)

//--------------------program-----------------------------------------

    c++:
    #include <iostream>
    using namespace std;

    int reverseInteger(int num) {
        int reversed = 0;

        while (num != 0) {
            int digit = num % 10;            
            reversed = reversed * 10 + digit; 
            num /= 10;                       
        }

        return reversed;
    }

    void reverseIntegerTest() {
        cout << "Enter an integer: ";
        int num;
        cin >> num;

        int reversedNum = reverseInteger(num);

        cout << "Reversed Integer: " << reversedNum << endl;
    }

    int main() {
        reverseIntegerTest();
        return 0;
    }


------------------------------------------------Question 16------------------------------------------

// Factorials of the number.
// pseudo code

pseudo functions:

function factorial(number-> int) -> int
    if (number < 0)
        return -1

    int result = 1

    for int i = 1...number              
        result= (result * i)            
    end for
    
    return result

function factorialTest(void) -> void
    input number
    int result = factorial(number)

    if (result == -1)
        print("Invalid number")
    else
        print("Factorial is" result)

factorialTest()


// c++ code

#include <iostream>
using namespace std;

int factorial(int number) {
    if (number < 0) {
        return -1; 
    }

    int result = 1;

    for (int i = 1; i <= number; i++) {
        result *= i;
    }

    return result;
}

void factorialTest() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    int result = factorial(number);

    if (result == -1) {
        cout << "Invalid number" << endl;
    } else {
        cout << "Factorial is " << result << endl;
    }
}

int main() {
    factorialTest(); 
    return 0;
}

--------------------------------------------------------------Question17---------------------------------------------------

//Fibonacci series
//Pseudocode:
function fibonacciNumbers(n -> [int], arrStore -> [int]) -> null
    if (n >= 1)
        arrStore[0] = 0
    end if
    
    if (n >= 2)
        arrStore[1] = 1
    end if
    
    first = 0
    second = 1
    next
    
    for (i = 3; i <= n; i++)
        next = first + second
        arrStore[i-1] = next
        first = second
        second = next
    end for
end fibonacciNumbers

function fibonacciNumbersTest(void)
    input n
    
    if (n < 1)
        print "Please enter a positive integer." 
        return
    end if
    
    if (n > MAX_SIZE)
        print "Please enter a number less than or equal to " << MAX_SIZE << "." 
        return
    end if
    
    int arrStore[MAX_SIZE] = {}
    
    fibonacciNumbers(n, arrStore)
    
    for (i = 0; i < n; i++)
        print arrStore[i] 
    end for
end fibonacciNumbersTest

start 
main()
    fibonacciNumbersTest()

    return EXIT_SUCCESS
end 

// c++ code for fibonacci series
#include <iostream>
#include<cstdlib>
#define MAX_SIZE 100
using std::cout;
using std::cin;
using std::endl;

void fibonacciNumbers(int n, int arrStore[]) 
{
    if (n >= 1) {
        arrStore[0] = 0;
    }
    if (n >= 2) {
        arrStore[1] = 1;
    }

    int first = 0, second = 1, next;

    for (int i = 3; i <= n; i++) {
        next = first + second;
        arrStore[i-1] = next;
        first = second;
        second = next;
    }
}

void fibonacciNumbersTest(void) 
{
    int n;
    cout << "Enter the number of terms : ";
    cin >> n;

    if (n < 1) {
        cout << "Please enter a positive integer." << endl;
        return;
    }
    if (n > MAX_SIZE) {
        cout << "Please enter a number less than or equal to " << MAX_SIZE << "." << endl;
        return;
    }
    
    int arrStore[MAX_SIZE] = {};

    fibonacciNumbers(n, arrStore);

    for (int i = 0; i < n; i++) 
    {
        cout << arrStore[i] << endl;
    }
    
}

int main(void) {
    fibonacciNumbersTest();

    return EXIT_SUCCESS;
}

----------------------------------------------------------Question 18---------------------------------------------------

// Print prime numbers in the limit

Pseudo Functions:

Function isPrime(number->int)->bool

    if number < 2

        Return False

    for i from 2 ..sqrt(number)

        if number % i == 0

            Return False

    Return True

Function printPrimeNumber(lowerLimit->int, upperLimit->int)

    for number from lowerLimit ..upperLimit

        if isPrime(number)

            Print number

Function printPrimeNumberTest()

    input lowerLimit
    input upperLimit

    printPrimeNumber(lowerLimit, upperLimit)

Pseudocode:

int main()

    printPrimeNumberTest()

CODE:

#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int number) 
{
    if (number < 2) 
    {
        return false;  
    }
    
    for (int i = 2; i <= sqrt(number); i++) 
    {
        if (number % i == 0) 
        {
            return false;  
        }
    }
    
    return true;  
}

void printPrimeNumber(int lowerLimit, int upperLimit) 
{
    for (int number = lowerLimit; number <= upperLimit; number++) 
    {
        if (isPrime(number)) 
        {
            cout << number << " ";  
        }
    }
}

void printPrimeNumberTest(void) 
{
    int lowerLimit, upperLimit;
    
    cout << "Enter the lower limit: ";
    cin >> lowerLimit;
    cout << "Enter the upper limit: ";
    cin >> upperLimit;
    
    cout << "Prime numbers between " << lowerLimit << " and " << upperLimit << ": ";

    printPrimeNumber(lowerLimit, upperLimit);
}

int main(void)
{
    printPrimeNumberTest();
    
    return 0;
}

----------------------------------------------------------Question 19--------------------------------------------

//To find an element from the array

//pseudocode

pseudo functions:

function findElement(number -> int, key -> int, arr[] -> int) -> int
	index -> int
	for i = 0..number
		if (arr[i] == key)
			index = i
		end if
	end for
	return index

function findElementTest()
	input number
	for i = 0..number
		input array
	end for
	result = findElement(num, key, arr)
	print result
	
end functions
	
pseudo code:

findElementTest()


//c++ code

#include <iostream>
using std::cout;
using std::cin;

int findElement(int number, int key, int arr[])
{
    	int i, index;
    	
    	for (i = 0 ; i < number ; i++)
    	{
        	if (arr[i] == key)
        	{
            		index = i;
            	}
    	}
    	
    	return index;
}

void findElementTest(void)
{
    	int key, arr[10], number, i;
    	
    	cout << "Enter the number of elements: ";
    	cin >> number;
    	
    	cout << "Enter elements: ";
    	for (i = 0 ; i < number ; i++)
    	{
        	cin >> arr[i];
        }
        
    	cout << "The element to find: ";
    	cin >> key;
    	
    	int result = findElement(number, key, arr);
    	
    	cout << "The index of element is: " << result;
}

int main(void)
{
    findElementTest();

    return 0;
}



------------------------------------------------Question 20------------------------------------------

// to find the largest number from array. 
// pseudo code

pseudo function:

function findLargest(array -> int[], size -> int) -> int
    set largest = array[0]
    for i from 1 to size-1
        if array[i] > largest then
            set largest = array[i]
        endif
    endfor
    return largest
end function

function findLargestTest()
    input size
    declare array[size]
    for i from 0 to size-1
        input array[i]
    endfor
    largest = findLargest(array, size)
    print largest
end function

pseudocode:

	findLargestTest()


// c++ code

#include <iostream>
using namespace std;

// Function to find the largest number in an array
int findLargest(int array[], int size) {
    int largest = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > largest) {
            largest = array[i];
        }
    }
    return largest;
}

// Function to test the findLargest function
void findLargestTest() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    int largest = findLargest(array, size);
    
    cout << "Largest element in the array: " << largest << endl; 
}

int main() {
    findLargestTest();
    return 0;
}




----------------------------------------------------------Question 21---------------------------------------------------

//To sort the elements in an array

pseudofunction

function sortelement( arr -> [int], size -> int) -> [int]
	int element
	for i from 0 to size-1
		enter the input
		arr[i] = element
	for i from 0 to size-1
		for j from i+1 to size-1
			if arr[i] > arr[j]
				temp = arr[i]
				arr[i] = arr[j]
				arr[j] = temp
	return arr

function sortelementtest()
	int arr
	size = 5
	sortelement()

	sorted array
	for i from 0 to size-1
		arr[i]
	

pseudocode

sortelementtest();

C++ code		

#include <iostream>
using namespace std;

int* sortelement( int arr[], int size)
{
	int element;
	for ( int i = 0; i < size; i++ )
	{
		cout << "enter the elements " << i + 1 << " : ";
		cin >> element;
		arr[i] = element;
	}
	for ( int i = 0; i < size; i++ )
	{
	    	for ( int j = i + 1; j < size; j++ )
	    	{
	    	    if (  arr[i] > arr[j])
	    	    {
	    	        int temp = arr[i];
	    	        arr[i] = arr[j];
	    	        arr[j] = temp;
	    	    }
	    	}

	}
	return arr;
}

void sortelementtest()
{
	int size = 5;
	int arr[ size ];
	sortelement(arr, size);
	
	cout << "Sorted array";
    for ( int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
	
}

int main(void)
{
    sortelementtest();
    
    return 0;
}

-------------------------------------------------------------Question 22-----------------------------------------------

//To find sum of n numbers

//pseudocode

pseudo functions:

function sumOfElements(number -> int)
	sum = 0 -> int
	for i = 0..number
		sum = sum + i
	end for
	return sum 

function sumOfElementsTest()
	input number
	result = sumOfElements(number)
	print result
	
end functions

pseudo code:

sumOfElementsTest()


//c++ code

#include <iostream>
using std::cout;
using std::cin;

int sumOfElements(int number)
{
    int i;
    int sum = 0;
    
    for(i = 0 ; i <= number ; i++)
    {
        sum = sum + i;
    }
    
    return sum;
}

void sumOfElementsTest(void)
{
    int number;
    
    cout << "Enter number of terms: ";
    cin >> number;
    
    int result = sumOfElements(number);
    cout << "Sum of first " << number << " numbers: " << result;
}

int main(void)
{
    sumOfElementsTest();
    
    return 0;
}

------------------------------------------------Question 23------------------------------------------

// to display the duplicate numbers in the array. [Josh]
// pseudo code

pseudo function:

function findDuplicates(array -> list of int, size -> int) -> void
    print "Duplicate numbers in the array are: "
    set hasDuplicates to false

    for i from 0 to size - 2
        for j from i + 1 to size - 1
            if array[i] == array[j]
                print array[i]
                set hasDuplicates to true
                break // Skip additional duplicates of the same number
            end if
        end for
    end for

    if hasDuplicates is false
        print "None"
    end if

function findDuplicatesTest() -> void
    input size
    declare array of size

    print "Enter the elements of the array: "
    for i from 0 to size - 1
        input array[i]
    end for

    call findDuplicates(array, size)


pseudocode:
    findDuplicatesTest()


// c++ code

#include <iostream>
using namespace std;

// Function to find and display duplicates in an array
void findDuplicates(int array[], int size) {
    cout << "Duplicate numbers in the array are: ";
    bool hasDuplicates = false;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                cout << array[i] << " ";
                hasDuplicates = true;
                break; // Skip additional duplicates of the same number
            }
        }
    }

    if (!hasDuplicates) {
        cout << "None";
    }

    cout << endl;
}

// Function to test the findDuplicates function
void findDuplicatesTest() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    findDuplicates(array, size);
}

int main() {
    findDuplicatesTest();
    return 0;
}


------------------------------------------------------- Question 24 -------------------------------------------------
program to check whether the strings are anagram.

---------------Pseudocode:-------------------------------------

function isAnagram(str1 --> string, str2 --> string) --> boolean

    if length of str1 != length of str2 then
        return false
    end if

   
    sort str1
    sort str2


    if str1 == str2 then
        return true
    else
        return false
    end if

end function

function isAnagramTest()

    input str1
    input str2

    result = isAnagram(str1, str2)

    if result == true then
        print "The strings are anagrams."
    else
        print "The strings are not anagrams."
    end if

end function

function main()

    isAnagramTest()
    return 0

end function


---------------Program---------------------

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string str1, string str2) {

    if (str1.length() != str2.length()) {
        return false;
    }

    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    
    return str1 == str2;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (isAnagram(str1, str2)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}

------------------------------------------------------------Question 25-----------------------------------------------------

//To find length of the string

//pseudocode

pseudo functions:

function findStringLength(str -> string&) -> int
	return str.length()
	
function findStringLengthTest()
	input string
	print "length of str is findStringLength(str)"
	
end functions

pseudo code:

findStringLengthTest()


//c++ code

#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::getline;
using std::string;

int findStringLength(const string& str)
{
    	return str.length();
}

void findStringLengthTest(void)
{
    	string str;
    	
    	cout << "Enter string: ";
    	getline(cin, str);
    	
    	cout << "The length of " << str << " is: " << findStringLength(str);
}

int main(void)
{
    	findStringLengthTest();
    
    	return 0;
}

------------------------------------------------Question 26------------------------------------------

// to delete duplicates strings in sting list. 
// pseudo code

pseudo functions:
function removeDuplicates(strings -> list of string, size -> int) -> int
    for i from 0 to size - 1
        for j from i + 1 to size - 1
            if strings[i] == strings[j]
                // Shift elements to the left
                for k from j to size - 2
                    strings[k] = strings[k + 1]
                end for
                size = size - 1 // Reduce the size of the list
                j = j - 1       // Adjust index to check the next element
            end if
        end for
    end for

    return size

function removeDuplicatesTest() -> void
    input size
    declare array strings of size

    print "Enter the strings: "
    for i from 0 to size - 1
        input strings[i]
    end for

    size = call removeDuplicates(strings, size)

    print "Strings after removing duplicates: "
    for i from 0 to size - 1
        print strings[i] with space
    end for
    print newline
	

pseudo code:
	removeDuplicatesTest()

// c++ code

#include <iostream>
#include <string>
using namespace std;

// Function to remove duplicate strings from a list
int removeDuplicates(string strings[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strings[i] == strings[j]) {
                // Shift elements to the left
                for (int k = j; k < size - 1; k++) {
                    strings[k] = strings[k + 1];
                }
                size--; // Reduce the size of the list
                j--;    // Adjust index to check the next element
            }
        }
    }
    return size;
}

// Function to test the removeDuplicates function
void removeDuplicatesTest() {
    int size;
    cout << "Enter the number of strings: ";
    cin >> size;

    string strings[size];
    cout << "Enter the strings: ";
    for (int i = 0; i < size; i++) {
        cin >> strings[i];
    }

    size = removeDuplicates(strings, size);

    cout << "Strings after removing duplicates: ";
    for (int i = 0; i < size; i++) {
        cout << strings[i] << " ";
    }
    cout << endl;
}

int main() {
    removeDuplicatesTest();
    return 0;
}



-------------------------------------------------------- Question 27---------------------------------------------------


//To count the number of vowels present in a string

pseudofunctions:

function countVowels(str --> string) --> int

    vowels = 0
    
    for i from 0...str[i]  
    
        if (str[i] =='a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' 
        || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')

             vowels++
        end if
        
    return vowels
    end for

end function

function countVowelsTest()
    
    input str

    vowels = countVowels(str)
       print "Total number of Vowels is : " 

pseudocode:
    
function main()

    countVowelsTest()
    return 0



C++ CODE:

#include <iostream>
#include <stdio.h>
using std::cout;
using std::cin;
using std::string;


int countVowels(string str)
{
    int vowels = 0;
    
    
    for (int i = 0; i<str[i]; i++)  
    {
        if (str[i] =='a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' 
        || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')

        {
		    vowels++;
        }
     }  
    return vowels;
}

void countVowelsTest(void)
{
    
    string str;

    cout << "Enter the string : ";
    cin >> str;

    int vowels = countVowels(str);
    cout << "Total number of Vowels : " << vowels;
    
}

int main(void)
{

     countVowelsTest();
     return 0;
}

------------------------------------------------Question 28------------------------------------------

// to count whitespaces in a sentence.  
// pseudo code

pseudo functions:

function countWhiteSpaces(sentence -> string) -> int
    initialize whitespaceCount to 0

    for each character in sentence
        if character is a whitespace
            increment whitespaceCount
        end if
    end for

    return whitespaceCount

function countWhiteSpacesTest(void)-> void
	initialize string sentence 
	input sentence
	int count = countWhiteSpaces(sentence)
	print count

pseudo code:
	countWhiteSpacesTest()

// c++ code

#include <iostream>
#include <string>
using namespace std;

int countWhitespaces(const string& sentence) {
    int whitespaceCount = 0;

    for (char c : sentence) {
        if (isspace(c)) {
            whitespaceCount++;
        }
    }

    return whitespaceCount;
}

void testCountWhitespaces() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    int count = countWhitespaces(sentence);

    cout << "Number of whitespaces: " << count << endl;
}

int main() {
    testCountWhitespaces();
    return 0;
}



//------------------------------------------------Question 29-----------------------------------------------------

//-------------------------------------------------Pseudocode-----------------------------------------------------

Read patients temperatures (integer) from keyboard till we read 0
    by using array / collection.
Find average temperature (integer), 
prime temperatures sum(example: 41, prime number temperature), 
minimum 3 digit temperatures sum, 
minimum temperature, 
odd temperatures sum (example: 31), and
2nd maximum odd temperature.  
Check minimum temperature is also prime temperature.
Use coding standards and best practices to write pseudo code and c++ code.
Plan the task codes to make as reusable functions.

-------------------------------------------------------------------------------


function readTemperature(temperature->[int] , size->int&)
function findTemperatureSum(temperature->[int] , size ->int)->int
function findTemperatureAverage(TemperatureSum , size ->int)->int
function isPrimeTemperature(number->int)->bool
function findPrimeTemperatureSum(temperature->[int] , size ->int)->int
function isNumberMinimum3Digit(number->int)->bool
function findMin3DigitSum(temperature->[int], size -> int) -> int 
function findMinTemperature(temperature->[int] , size ->int)->int
function isOddTemperature(number -> int) -> bool
function findSumOfOddTemperature(temperature->[int] , size ->int)->int
function find2ndMaxOddTemperature(temperature->[int] , size ->int)->int






function readTemperature(temperatures->[int],size->int&)
       
       input i=0
       int currentTemperature
       while(true)
           print "enter the patient's temperature"
           read currentTemperature
           if(currentTemperature!=0)
                ++size
                temperatures[i]=currentTemperature
                ++i
            else
               break
            end if
        end while
end function                

function findTemperatureSum(temperature->[int] , size ->int)->int
       int sum = 0
       for i in temperatures
             sum + = temperatures[i]
       end for
       return sum
end function

function findTemperatureAverage(TemperatureSum->int , size ->int)->int
        return (TemperatureSum/size);
end function





function isPrimeTemperture(currentTemperature -> [int]) - bool

    if (currentTemperature <= 1)
        return false
    end if
    for (i = 2; i <= (currentTemperature / 2); i = i + 1)
        if (currentTemperature % i == 0)
            return false
        end if
    end for
    return true


function findPrimeTemperatureSum(temperatures -> [int], size -> [int]) -> [int]

    initialize sum = 0
    for (int i =0; i<size; i++)
        currentTemperature = temperatures[i]

        if (isPrimeTemperture(currentTemperature -> [int]) == true)
            sum += currentTemperature
        end if
    end for

    return sum




function isOddTemperature(number -> int) -> bool

    if (number % 2 != 0)
        return true
    else
        return false
    end if
    
end function

function findSumOfOddTemperature(temperature->[int] , size ->int)->int

    int oddSum = 0;
    
    for i from 0 ..size-1
    
        if (isOddTemperature(number))
            oddSum = (oddSum + number)
        end if
        
    end for
    
    return oddSum
    
end function






function isNumberMinimum3Digit( temperature -> [int] , size -> int , qualify -> [int]) -> bool
    count = 0
    for i in temperatures
        if ( temperatures[i] >= 100 )
            qualify[count] = temperatures[i]
            count++
    return count
            

function findMin3DigitSum( qualify -> [int], count -> int ) ->int
    for i in qualify
        sum += qualify[i]
    return sum






function find2ndMaxOddTemperature(temperatures[]-->int, size-->int)-->int

  maxOdd = INT_MIN
    secondMaxOdd = INT_MIN
    
     for i from 0...size
     
         if(isOddTemperature(number))
          
            if (temperatures[i]> maxOdd) 
            
                secondMaxOdd = maxOdd
                maxOdd = temperatures[i]
                
            end if
            else if (temperatures[i] > secondMaxOdd && temperatures[i] != maxOdd) 
            
                secondMaxOdd = temperatures[i]
                
            end elseif
        end if
    end for
    
    if (secondMaxOdd == INT_MIN)
     
          print " No second maximum odd temperature found " 
          return -1
     end if
     
     return secondMaxOdd



function findMinTemperature(temperature->[int],size->int)->int
    minTemp = MAX_INT
    for i in teperature[]
        if temperature[i] < minTemp
        minTemp = temperature[i]
return minTemp

function Test()
    //temperature [int]
    size=0
    readTemperature(temperature, size)
    TemperatureSum= findTemperatureSum(temperature->[int] , size ->int)->int
    averageTemperature = findTemperatureAverage(TemperatureSum, size)
    primeTemperatureSum = findPrimeTemperatureSum(temperature, size)

    
    int count= isNumberMinimum3Digit(temperatures, size, qualify);
    min3DigitTemperatureSum = findMin3DigitSum(qualify, count)


    minimumTemperature = findMinTemperature(temperature, size)
    oddTemperatureSum = findSumOfOddTemperature(temperature , size)
    secondMaxOddTemperature = find2ndMaxOddTemperature(temperature, size)
    print averageTemperature
    print primeTemperatureSum
    print min3DigitTemperatureSum
    print minimumTemperature
    print oddTemperatureSum
    print secondMaxOddTemperature
    if isprime(minimumTemperature)
         print "The minimum temperature is an prime number"
    else
         print "The minimum temperature is not a prime number"  

pseudoMain 
    Test()





//----------------------------------------------Program with array-------------------------------------------------


#include<iostream>
using namespace std;
#define MAX_SIZE 1000
#include<cstdlib>
#include <climits>
#include <cmath>

//abel

void readTemperature(int temperatures[],int& size)
{
       int i=0; //for iteration
       int currentTemperature=0;
       do
        {
            
         cout << "enter the patient's temperature " << (i+1) << ": ";
         cin >> currentTemperature;
            if (currentTemperature!=0)
            {    ++size;
                temperatures[i] = currentTemperature;
                ++i;
            }
                
        }
          while(currentTemperature!=0); 
          
        
 
}  
int findTemperatureSum(int temperatures[] , int size )
{
    int sum = 0;
    for (int i=0; i < size; i++)
    {
        sum += temperatures[i];
    }
    return sum;
}

int findTemperatureAverage(int temperatureSum , int size)
{
    return (temperatureSum/size);
}

//sreya

bool isOddTemperature(int number) 
{
    if (number % 2 != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findSumOfOddTemperature(int temperatures[] , int size)
{
    int oddSum = 0;
    int number;
    
    for (int i = 0; i <= size-1; i++)
    {    
        number = temperatures[i];
        if (isOddTemperature(number))
        {
            oddSum = (oddSum + number);
        }
    }
    
    return oddSum;
}

//sooraj

int isNumberMinimum3Digit( int temperatures[] , int size, int qualify[])
{
    int count = 0;
    for( int i = 0; i < size; i++)
    {
        if ( temperatures[i] >= 100 )
        {
            qualify[count] = temperatures[i];
            count++;
        }
    }
    return count;
}
            

int findMin3DigitSum( int qualify[], int count )
{   
    int sum = 0;
    for (int i = 0; i<count; i++)
    {
        sum += qualify[i];
    }
    return sum;
}







//athira

int find2ndMaxOddTemperature(int temperatures[], int size)

{
int maxOdd = INT_MIN, secondMaxOdd = INT_MIN;
     for(int i = 0;i < size; i++)
     {
          int number = temperatures[i];
          if(isOddTemperature(number))
          {

            if (temperatures[i]> maxOdd) 
            {
                secondMaxOdd = maxOdd;
                maxOdd = temperatures[i];
            } 
            else if (temperatures[i] > secondMaxOdd && temperatures[i] != maxOdd) 
            {
                secondMaxOdd = temperatures[i];
            }
          }
     }
     if (secondMaxOdd ==INT_MIN)
     {
         cout << " No second maximum odd temperature found " << endl;
         return -1;
     }
     return secondMaxOdd;
}



//minhaj

int findMinntemperature(int temperatures[],int size)
{
    int minTemp = MAX_SIZE;
    for(int i =0;i<size;i++)
    {
         if(temperatures[i] < minTemp)
        {
            minTemp = temperatures[i];
        }
    }
    return minTemp;
}

//venkatesh

bool isPrimeTemperture(int currentTemperature)
{
    if (currentTemperature <= 1)
    {
        return false;
    }
    
    for (int i = 2; i <= sqrt(currentTemperature); i++)
    {
        if (currentTemperature % i == 0)
        {
            return false;
        }
    }
    return true;
} 


// c++ code for find Prime Temperature Sum
int findPrimeTemperatureSum(int temperatures[], int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        int currentTemperature = temperatures[i];

        if (isPrimeTemperture(currentTemperature) == true)
        {
            sum += currentTemperature;
        }
    }

    return sum;
}


void Test()
{
    int temperatures[MAX_SIZE];
    int size = 0;
    int qualify[MAX_SIZE];

    readTemperature(temperatures , size);
    int temperatureSum     = findTemperatureSum(temperatures , size);
    int averageTemperature = findTemperatureAverage(temperatureSum , size);
    int sumOfOddTemperature = findSumOfOddTemperature(temperatures , size);
    int count= isNumberMinimum3Digit(temperatures, size, qualify);
    int sum3Digit = findMin3DigitSum( qualify, count );
    int minimumTemperature = findMinntemperature(temperatures , size);
    int secondMaximumOddTemperature      = find2ndMaxOddTemperature(temperatures , size);
    int sumOfPrimeTemperatureSum  =findPrimeTemperatureSum(temperatures , size);
    
     
    cout << "The Average Temperature is: " << averageTemperature << endl;
    cout << "Minimum Temperature is: " << minimumTemperature << endl;
    cout << "Sum of Odd Temperatures is: " << sumOfOddTemperature << endl;

    if(secondMaximumOddTemperature == -1)
    {
        cout << " No second maximum odd temperature found as there is only 1 odd prime" << endl;
    }
    else
    {
        cout << "Second Maximum of Odd Temperatures is: " << secondMaximumOddTemperature<< endl;  
    }            
    
    cout << "Sum of 3 Digits is: " << sum3Digit << endl;
    cout << "Sum of Prime Temperature is: " << sumOfOddTemperature <<endl;
    


}


int main()
{
    Test();
    return EXIT_SUCCESS;
}


//------------------------------------------------Question 30-----------------------------------------------------

//-------------------------------------------------Pseudocode wihtout array-----------------------------------------------------
 

function findMinimumTemperature(current -> int, min -> int) -> int
    if current < min
        min = current
    return min
end function

function readTemperature(temperatures -> int, size -> int, min -> int)
    initialize i as 0
    initialize currentTemperature as 0
    do
        prompt "Enter the patient's temperature (i+1):"
        read currentTemperature
        if currentTemperature != 0
            increment size by 1
            add currentTemperature to temperatures
            set min to findMinimumTemperature(currentTemperature, min)
            increment i by 1
        end if
    while currentTemperature != 0
end function

function findTemperatureAverage(temperatures -> int, size -> int) -> int
    return (temperatures / size)
end function

function Test()
    initialize min to MAX_SIZE
    initialize size to 0
    initialize temperatures to 0
    call readTemperature(temperatures, size, min)
    set averageTemperature to findTemperatureAverage(temperatures, size)
    print "The minimum Temperature is: ", min
    print "The Average Temperature is: ", averageTemperature
end function

function main()
    call Test()
    return EXIT_SUCCESS
end function



//--------------------------------------------------Program without array-------------------------------------------------------

#include<iostream>
using namespace std;
#define MAX_SIZE 1000
#include<cstdlib>
#include <climits>
#include <cmath>

//abel


int findMinimumTemperature(int current , int min )
{ 
   if(current < min)
   {
       min = current;
   }
   return min;
}

void readTemperature(int& temperatures,int& size,int& min)
{
       int i=0; //for iteration
       int currentTemperature=0;
       
       do
        {
            
         cout << "enter the patient's temperature " << (i+1) << ": ";
         cin >> currentTemperature;
            if (currentTemperature!=0)
            {    ++size;
                temperatures += currentTemperature;
                min = findMinimumTemperature(currentTemperature , min);
                ++i;
            }
                
        }
          while(currentTemperature!=0);         
 
}  

int findTemperatureAverage(int temperatures , int size)
{
    return (temperatures/size);
}

void Test()
{
    int min = MAX_SIZE;
    int size = 0;
    int temperatures=0;

    readTemperature(temperatures , size, min);
    
    int averageTemperature = findTemperatureAverage(temperatures , size);
    
    cout << "The minimum Temperature is: " << min << endl;
    cout << "The Average Temperature is: " << averageTemperature << endl;
   
  
}

int main()
{
    Test();
    return EXIT_SUCCESS;
}
