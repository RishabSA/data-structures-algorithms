#include <iostream>
#include <list>

/*
Notes:

Define a doubly linked list in c++ with std::list
#include <list> must be included to use it
*/

int main() {
    // std::list<int> defines a doubly linked list
    std::list<int> doubly_linked_list = {3, 10};

    // push_back() - Add to the end of the linked list O(1)
    doubly_linked_list.push_back(5);
    doubly_linked_list.push_back(20);

    // push_front() - Add to the beginning of the linked list O(1)
    doubly_linked_list.push_front(10);

    // Iterate through the doubly linked list like a regular array O(N)
    std::cout << "Elements in the list (after pushing): ";
    for (int val : doubly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // begin() - Get the first element of the linked list as an iterator O(1)
    auto iterator = doubly_linked_list.begin();
    advance(iterator, 2); // Get the third element of the linked list as an iterator O(N)

    // insert_after() - Insert a new element after a specific element O(1)
    doubly_linked_list.insert(iterator, 25); 

    std::cout << "Elements in the list (after inserting): ";
    for (int val : doubly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // front() - Access the first element of the doubly linked list O(1)
    std::cout << "First element: " << doubly_linked_list.front() << std::endl;

    // back() - Access the last element of the doubly linked list O(1)
    std::cout << "Last element: " << doubly_linked_list.back() << std::endl;
    
    // next(l.begin(), i) - Access the ith element of the doubly linked list O(N)
    std::cout << "Element at index 2: " << *next(doubly_linked_list.begin(), 2) << std::endl;

    iterator = doubly_linked_list.begin();
    advance(iterator, 2); // Get the third element of the linked list as an iterator O(N)

    // Update the value of an element in the linked list O(1)
    *iterator = 8;

    std::cout << "Elements in the list (after updating): ";
    for (int val : doubly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // remove() - Remove all occcurrences of an element O(N)
    doubly_linked_list.remove(8);

    std::cout << "Elements in the list (after removing): ";
    for (int val : doubly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // pop_back() - Delete the last element in the doubly linked list O(1)
    doubly_linked_list.pop_back();

    // pop_front() - Delete the first element in the doubly linked list O(1)
    doubly_linked_list.pop_front();

    std::cout << "Elements in the list (after popping front and back): ";
    for (int val : doubly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}