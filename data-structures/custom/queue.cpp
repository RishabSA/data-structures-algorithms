#include <iostream>
#include "doubly_linked_list.cpp"

/*
Notes:

Instead of using a full array which has too much overhead, most queues use linked lists.
Queues are a type of linear data structure that use a First In First Out (FIFO) principle - like a grocery store line.
*/

class Queue {
public:
    // Storage with a linked list
    LinkedList ll = LinkedList();

    // O(1)
    void push(int val) {
        ll.append(val);
    };

    // O(1)
    Node* pop() {
        return ll.removeFirst();
    };

    // O(1)
    Node* peek() {
        return ll.head;
    };
};

int main() {
    Queue messageQueue;
    std::cout << "Running Message Queue Test..." << std::endl;
    std::cout << "Is queue empty? " << (messageQueue.ll.getLength() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    // Test Case 1: Enqueue messages
    std::cout << "Enqueuing messages: 10, 20, 420" << std::endl;
    messageQueue.push(10);
    messageQueue.push(20);
    messageQueue.push(420);
    std::cout << "Is queue empty now? " << (messageQueue.ll.getLength() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "Expected front message: 10" << std::endl;
    std::cout << "Actual front message: " << messageQueue.peek()->current << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    // Test Case 2: Dequeue messages in order
    std::cout << "Dequeuing messages in order:" << std::endl;
    std::cout << "Message 1: " << messageQueue.pop()->current << std::endl; // Should be 10
    std::cout << "Message 2: " << messageQueue.pop()->current << std::endl; // Should be 20
    std::cout << "Message 3: " << messageQueue.pop()->current << std::endl; // Should be 420
    std::cout << "Is queue empty now? " << (messageQueue.ll.getLength() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    return 0;
}