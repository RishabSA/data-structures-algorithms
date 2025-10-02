#include <iostream>

class Node {
public:
    int current;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int c) {
        current = c;
    };
};