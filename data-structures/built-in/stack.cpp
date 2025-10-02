#include <iostream>

/*
Notes:

Stacks are a type of linear data structure that use a Last In First Out (LIFO) principle - like a stack of books.

std::stack is a built-in C++ stack implementation:

std::stack<int> stack_name;
stack_name.push(x); // Adds an element to the top of the stack
stack_name.pop(); // Removes the element from the top of the stack
stack_name.top(); // Accesses the element at the top of the stack without removing it
stack_name.empty(); // Checks if the stack is empty
stack_name.size(): // Returns the number of elements in the stack
*/

int convertParentheses(const char expression) {
    switch(expression) {
        case '(':
        case ')':
            return 1;
        case '[':
        case ']':
            return 2;
        case '{':
        case '}':
            return 3;
        default:
            return 4;
    }
}

bool isBalanced(const std::string& expression) {
    std::stack<char> p_stack;

    // O(N)
    for (char i : expression) {
        if (i == '(' || i == '[' || i == '{') p_stack.push(i);
        else if (p_stack.empty()) return false;
        else if (p_stack.top() == '(' && i == ')') p_stack.pop();
        else if (p_stack.top() == '[' && i == ']') p_stack.pop();
        else if (p_stack.top() == '{' && i == '}') p_stack.pop();
        else return false;
    }

    return p_stack.empty();
}

void runTestCase(const std::string& expression, bool expected) {
    std::cout << "Testing expression: \"" << expression << "\"" << std::endl;
    bool result = isBalanced(expression);
    std::cout << "Result: " << (result ? "Balanced" : "Not Balanced") << std::endl;
    std::cout << "Status: " << (result == expected ? "PASS" : "FAIL") << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

int main() {
    // Correctly balanced expressions
    runTestCase("()", true);
    runTestCase("()[]{}", true);
    runTestCase("{[]}", true);
    runTestCase("{{([])}}", true);
    runTestCase("", true); // Empty string is balanced

    // Incorrectly balanced expressions
    runTestCase("(", false);
    runTestCase(")", false);
    runTestCase("([)]", false);
    runTestCase("{[}]", false);
    runTestCase("((()", false);

    // This is an extremely long and complex, but correctly balanced, expression.
    // It is designed to rigorously test nested parentheses, brackets, and braces.
    std::string long_balanced_expression = 
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[()()()()()]}{[()()()()()]}{[()()()()()]}{[()()()()()]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) "
        "{[[()]]}{[[()]]}{[[()]]}{[[()]]} "
        "({[]})({[]})({[]})({[]}) "
        "([{}])([{}])([{}])([{}]) ";
    
    // runTestCase(long_balanced_expression, true);

    return 0;
}