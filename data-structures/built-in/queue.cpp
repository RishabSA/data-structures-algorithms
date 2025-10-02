#include <iostream>

/*
Notes:

Queues are a type of linear data structure that use a First In First Out (FIFO) principle - like a grocery store line.

std::queue is a built-in C++ queue implementation:

std::queue<int> queue_name;
queue_name.push(x); // Adds an element to the back of the queue
queue_name.pop(); // Removes the element from the front of the queue
queue_name.front(); // Accesses the element at the front of the queue without removing it
queue_name.back(); // Accesses the element at the back of the queue without removing it
queue_name.empty(); // Checks if the queue is empty
queue_name.size(): // Returns the number of elements in the queue
*/

int main() {
    std::queue<int> messageQueue;
    std::cout << "Running Message Queue Test..." << std::endl;
    std::cout << "Is queue empty? " << (messageQueue.size() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    // Test Case 1: Enqueue messages
    std::cout << "Enqueuing messages: 10, 20, 420" << std::endl;
    messageQueue.push(10);
    messageQueue.push(20);
    messageQueue.push(420);
    std::cout << "Is queue empty now? " << (messageQueue.size() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "Expected front message: 10" << std::endl;
    std::cout << "Actual front message: " << messageQueue.front() << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    // Test Case 2: Dequeue messages in order
    std::cout << "Dequeuing messages in order:" << std::endl;
    std::cout << "Message 1: " << messageQueue.front() << std::endl; // Should be 10
    messageQueue.pop();
    std::cout << "Message 2: " << messageQueue.front() << std::endl; // Should be 20
    messageQueue.pop();
    std::cout << "Message 3: " << messageQueue.front() << std::endl; // Should be 420
    messageQueue.pop();
    std::cout << "Is queue empty now? " << (messageQueue.size() == 0 ? "Yes" : "No") << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    return 0;
}