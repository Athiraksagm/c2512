#include <iostream>
#include <stdexcept>
#include <vector>

// Custom exceptions
class StackOverflowException : public std::exception 
{
public:
    const char* what() const noexcept override
   {
        return "Stack Overflow";
    }
};

class StackUnderflowException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Stack Underflow";
    }
};

// Generic stack implementation
template <typename T>
class C2512Stack 
{
private:
    std::vector<T> arr; // Dynamic array for storage
    size_t _size;       // Maximum size of the stack
    int _top;           // Index of the top element

public:
    // Constructor
    C2512Stack(size_t size = 100) : _size(size), _top(-1) {}

    // Push method
    void push(const T& data)
   {
        if (_top >= static_cast<int>(_size) - 1)
        {
            throw StackOverflowException();
        }
        if (_top + 1 < arr.size()) 
        {
            arr[_top + 1] = data;
        } else 
        {
            arr.push_back(data);
        }
        _top++;
    }

    // Pop method
    void pop() 
       {
        if (_top < 0) 
        {
            throw StackUnderflowException();
        }
        _top--;
    }

    // Top method
    T top() const 
       {
        if (_top < 0)
        {
            throw StackUnderflowException();
        }
        return arr[_top];
    }
};

int main() 
 {
    try 
      {
        // Create a stack with default size
        C2512Stack<double> stack;

        stack.push(10.0);
        stack.push(12.0);
        stack.push(11.0);

        std::cout << stack.top() << std::endl; // 11.0
        stack.pop();

        std::cout << stack.top() << std::endl; // 12.0
        stack.pop();

        std::cout << stack.top() << std::endl; // 10.0
        stack.pop();

        // Attempt to access top of an empty stack
        std::cout << stack.top() << std::endl; // Err/Underflow

    } catch (const std::exception& ex) 
      {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}
