#include <iostream>
using namespace std;

class C2512Stack {
    private:
        static const int _size = 3;  // Static constant for array size
        double arr[_size];             // Array size can now use a constant expression
        int _top;

    public:
        // Constructor
        C2512Stack() {
            _top = 0; // Stack is initially empty
        }

        // Push method to add elements to the stack
        void push(double data) {
            if (_top >= _size) { // Check for overflow
                cout << "Error: Stack Overflow" << endl;
            } else {
                arr[_top] = data;
                _top++;
            }
        }

        // Pop method to remove elements from the stack
        void pop() {
            if (_top <= 0) { // Check for underflow
                cout << "Error: Stack Underflow" << endl;
            } else {
                _top--;
                cout << "Popped: " << arr[_top] << endl; // Display popped element
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
    C2512Stack stack;

    stack.push(10.0);
    stack.push(12.0);
    stack.push(11.0);
    stack.push(17.0);
    stack.top(); // Top: 11.0
    stack.pop(); // Popped: 11.0
    stack.top(); // Top: 12.0
    stack.pop(); // Popped: 12.0
    stack.top(); // Top: 10.0
    stack.pop(); // Popped: 10.0
    stack.top(); // Error: Stack is empty

    return 0;
}
