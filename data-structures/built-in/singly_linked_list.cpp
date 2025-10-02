#include <iostream>
#include <forward_list>

/*
Notes:

Define a singly linked list in c++ with std::forward_list
#include <forward_list> must be included to use it

Due to its singly linked nature, std::forward_list does not provide direct access to the size or the last element without traversal.
*/

int main() {
    // std::forward_list<int> defines a singly linked list
    std::forward_list<int> singly_linked_list = {3, 10};

    // push_front() - Add to the beginning of the linked list O(1)
    singly_linked_list.push_front(10);
    singly_linked_list.push_front(5);
    singly_linked_list.push_front(10);

    // Iterate through the singly linked list like a regular array O(N)
    std::cout << "Elements in the list (after pushing): ";
    for (int val : singly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // begin() - Get the first element of the linked list as an iterator O(1)
    auto iterator = singly_linked_list.begin();
    advance(iterator, 2); // Get the third element of the linked list as an iterator O(N)

    // insert_after() - Insert a new element after a specific element O(1)
    singly_linked_list.insert_after(iterator, 25); 

    std::cout << "Elements in the list (after inserting): ";
    for (int val : singly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // remove() - Remove all occcurrences of an element O(N)
    singly_linked_list.remove(10);

    std::cout << "Elements in the list (after removing): ";
    for (int val : singly_linked_list) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}