#include <iostream>
#include "doubly_linked_list.cpp"

/*
Notes:

Instead of using a full array which has too much overhead, most stacks use linked lists.
Stacks are a type of linear data structure that use a Last In First Out (LIFO) principle - like a stack of books.
*/

class Stack {
public:
    // Storage with a linked list
    LinkedList ll = LinkedList();

    // O(1)
    void push(int val) {
        ll.append(val);
    };

    // O(1)
    Node* pop() {
        return ll.pop();
    };

    // O(1)
    Node* peek() {
        return ll.tail;
    };
};

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

// O(N)
bool isBalanced(const std::string& expression) {
    Stack numStack = Stack();

    for (char i : expression) {
        if (i == ' ') continue;

        if (i == '(' || i == '[' || i == '{') {
            // Push
            numStack.push(convertParentheses(i));
        } else if (numStack.peek() && numStack.peek()->current == convertParentheses(i)) {
            // Pop
            numStack.pop();
        } else {
            return false;
        }
    }

    return numStack.ll.getLength() == 0;
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