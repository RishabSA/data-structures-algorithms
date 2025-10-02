#include <iostream>

class Node {
public:
    int val;
    Node* next = nullptr;

    Node(int v) {
        val = v;
    }

    static void log(std::string text) {
        std::cout << "[Log] " << text << std::endl;
    };
};

int main() {
    // std::string text = "Hello World";
    // std::cout << &text << std::endl;

    Node* current;

    std::cout << &current << std::endl;
    std::cout << &current->val << std::endl;
    std::cout << &current->next << std::endl;

    std::cout << std::endl;

    Node::log("Testing123");

    return 0;
}