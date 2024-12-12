#include <iostream>
#include <stdexcept>  // For std::exception
using namespace std;

// Custom exception for stack overflow
class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack Overflow";
    }
};

// Custom exception for stack underflow
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Stack Underflow";
    }
};

template <typename T>
class C2512Stack {
    private:
        static const int _size = 3;  // Static constant for array size
        T arr[_size];                // Array can store any type of data (template)
        int _top;

    public:
        // Constructor
        C2512Stack() {
            _top = 0; // Stack is initially empty
        }

        // Push method to add elements to the stack
        void push(T data) {
            try {
                if (_top >= _size) { // Check for overflow
                    throw StackOverflowException();  // Throw overflow exception
                } else {
                    arr[_top] = data;
                    _top++;
                }
            }
            catch (const StackOverflowException& e) {
                cout << e.what() << endl;  // Handle overflow exception
            }
        }

        // Pop method to remove elements from the stack
        void pop() {
            try {
                if (_top <= 0) { // Check for underflow
                    throw StackUnderflowException();  // Throw underflow exception
                } else {
                    _top--;
                    cout << "Popped: " << arr[_top] << endl; // Display popped element
                }
            }
            catch (const StackUnderflowException& e) {
                cout << e.what() << endl;  // Handle underflow exception
            }
        }

        // Top method to get the top element of the stack (no return value)
        void top() {
            if (_top <= 0) { // Check if the stack is empty
                cout << "Error: Stack is empty" << endl;
            } else {
                cout << "Top: " << arr[_top - 1] << endl; // Display the top element
            }
        }
};

// Driver code
int main() {
    // Create stack for double type
    C2512Stack<double> stack;

    // Pushing elements onto the stack
    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);
    
    // Trying to push another element (this will cause overflow)
    stack.push(17.0);  // This should trigger the overflow exception

    // Displaying the top element and popping it
    stack.top();  // Top: 11.0
    stack.pop();  // Popped: 11.0
    stack.top();  // Top: 12.0
    stack.pop();  // Popped: 12.0
    stack.top();  // Top: 10.0
    stack.pop();  // Popped: 10.0
    stack.pop();  // Error: Stack Underflow
    stack.top();  // Error: Stack is empty

    // Create stack for int type
    C2512Stack<int> intStack;

    // Pushing elements onto the stack for int type
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    // Trying to push another element (this will cause overflow for intStack)
    intStack.push(4);  // This should trigger the overflow exception

    // Displaying the top element and popping it
    intStack.top();  // Top: 3
    intStack.pop();  // Popped: 3
    intStack.top();  // Top: 2
    intStack.pop();  // Popped: 2
    intStack.top();  // Top: 1
    intStack.pop();  // Popped: 1
    intStack.pop();  // Error: Stack Underflow
    intStack.top();  // Error: Stack is empty

    return 0;
}
