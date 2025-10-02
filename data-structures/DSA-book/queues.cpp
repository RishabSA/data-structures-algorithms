#include <iostream>
#include <queue>

int main() {
    std::queue<int> queue; // Queues use FIFO (First In, First Out)

    // Enqueue
    queue.push(10);
    queue.push(12);
    queue.push(9);
    queue.push(8);
    queue.push(3);

    std::cout << "The queue has " << queue.size() << " elements." << "\n";
    std::cout << "\n";

    // Front and Back Elements
    std::cout << "The front element is: " << queue.front() << "\n";
    std::cout << "The back element is: " << queue.back() << "\n";
    std::cout << "\n";

    // Dequeue
    queue.pop();
    queue.pop();

    std::cout << "(After dequeue) The front element is: " << queue.front() << "\n";
    std::cout << "(After dequeue) The back element is: " << queue.back() << "\n";

    return 0;
}