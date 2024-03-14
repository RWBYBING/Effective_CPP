// Item 1: View C++ as a federation of languages

// C++ was called "C With Class" in early years.
// Actually C++ is kind of federation of languages.
// C++ is a collection of the following features.
// 1. C
// 2. Object-Oriented C++
// 3. Template C++
// 4. The STL

#include <iostream>
#include <vector>
#include <algorithm>

// Procedural programming example: calculating factorial (C-Style)
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Object-oriented programming example: representing a simple shape
class Shape
{
public:
    virtual void draw() const = 0;
};

// Templating metaprogramming: find the maximum of two values
template <typename T>
T maxValue(T a, T b)
{
    return (a > b) ? a : b;
}

// Derived class representing a rectangle
class Rectangle : public Shape
{
public:
    void draw() const override
    {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main()
{
    // Procedural programming: calculating factorial
    int num = 5;
    std::cout << "Factorial of " << num << "is : " << factorial(num) << std::endl;

    // Object-oriented programming: drawing a rectangle
    Rectangle rect;
    rect.draw();

    // Using C++ Standard Library: sorting a vector
    std::vector<int> numbers = {3, 1, 4, 1, 5};
    std::sort(numbers.begin(), numbers.end());
    std::cout << "Sorted numbers: ";
    for (int num : numbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Calling the max function with different types
    int intMax = maxValue(3, 7);
    double doubleMax = maxValue(4.5, 2.3);

    // Output the results
    std::cout << "Maximum of 3 and 7 is: " << intMax << std::endl;
    std::cout << "Maximum of 4.5 and 2.3 is: " << doubleMax << std::endl;

    return 0;
}

