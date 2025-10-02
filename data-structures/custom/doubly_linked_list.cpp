#include <iostream>
#include "linked_list_node.cpp"

/*
Notes:

A doubly linked list is a linear collection of nodes, where  each node contains data, a pointer to the next node, and a pointer to the previous node, allowing for both forward and backward traversal.

Access by index: O(N)
Search by value: O(N)
Insert at head: O(1)
Delete head: O(1)
Insert at tail: O(1)
Delete tail: O(1)
Insert after given node/iterator: O(1)
Insert before given node/iterator: O(1)
Delete given node when you have its iterator: O(1)
Splice/move nodes given iterators: O(1)
Forward traversal: O(N)
*/

class LinkedList {
private:
    int length = 0;

public:
    Node* head = nullptr;
    Node* tail = nullptr;

    int getLength() {
        return length;
    }

    LinkedList(int val) {
        length++;
        head = new Node(val);
        tail = head;
    };

    LinkedList() = default;

    // O(N)
    void printAll() {
        Node* currentNode = head;

        while (currentNode != nullptr) {
            std::cout << currentNode->current << std::endl;
            currentNode = currentNode->next;
        }
    };

    // O(1)
    bool append(int newVal) {
        length++;

        if (tail == nullptr) {
            head = new Node(newVal);
            tail = head;
            return true;
        }

        Node* newNode = new Node(newVal);
        newNode->prev = tail;
        tail->next = newNode;

        tail = tail->next;

        return true;
    };

    // O(1)
    Node* removeFirst() {
        if (head == nullptr) return nullptr;

        length--;

        Node* originalHead = head;

        if (head->next == nullptr) {
            head = nullptr;
            tail = nullptr;

            return originalHead;
        }

        head = head->next;
        head->prev = nullptr;

        return originalHead;
    };

    // O(1)
    Node* pop() {
        if (head == nullptr) return nullptr;

        length--;

        if (tail->prev == nullptr) {
            Node* removed = tail;
            head = nullptr;
            tail = nullptr;

            return removed;
        }

        Node* removed = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;

        return removed;
    };

    // O(N)
    Node* insert(int item, int index) {
        if (index < 0) return nullptr;

        if (head == nullptr) {
            if (index == 0) {
                Node* newNode = new Node(item);

                head = newNode;
                tail = head;
                
                length++;
                return newNode;
            } else {
                return nullptr;
            }
        }

        // O(1)
        if (index == 0) {
            Node* newNode = new Node(item);

            newNode->next = head;
            head->prev = newNode;
            head = newNode;

            length++;
            return newNode;
        }

        Node* currentNode = head;
        int counterIdx = 1;

        length++;

        while (currentNode->next != nullptr && counterIdx != index) {
            currentNode = currentNode->next;
            counterIdx++;
        }

        Node* newNode = new Node(item);

        newNode->next = currentNode->next;
        newNode->prev = currentNode;
        currentNode->next->prev = newNode;
        currentNode->next = newNode;

        if (currentNode == tail) {
            tail = newNode;
        }

        return newNode;
    };

    // O(N)
    int getIndex(int item) {
        int index = 0;

        Node* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->current != item) {
                currentNode = currentNode->next;
                index++;
            } else {
                return index;
            }
        }

        return -1;
    };

    // O(N)
    Node* nodeAtIndex(int index) {
        if (index < 0 || index > length - 1) return nullptr;

        int counterIdx = 0;

        Node* currentNode = head;
        while (currentNode->next != nullptr && index != counterIdx) {
            currentNode = currentNode->next;
            counterIdx++;
        }

        return currentNode;
    };

    // O(N)
    Node* remove(int val) {
        if (head == nullptr) return nullptr;

        // O(1)
        if (head->current == val) {
            Node* nodeToDelete = head;

            head = head->next;
            if (head == nullptr) tail = nullptr;
            else head->prev = nullptr;

            nodeToDelete->next = nullptr;
            return nodeToDelete;
        }

        Node* currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->current != val) {
            currentNode = currentNode->next;
        }

        if (currentNode->next == nullptr) return nullptr;

        Node* nodeToDelete = currentNode->next;
        currentNode->next = nodeToDelete->next;
        nodeToDelete->next->prev = currentNode;

        if (nodeToDelete == tail) tail = currentNode;

        nodeToDelete->next = nullptr;

        return nodeToDelete;
    };
};

// int main () {
//     LinkedList ll = LinkedList(5);
//     ll.append(10);
//     ll.append(15);
//     ll.append(17);

//     std::cout << "Length of the linked list: " << ll.getLength() << std::endl;

//     ll.printAll();

//     ll.pop();

//     std::cout << std::endl;
//     ll.printAll();

//     ll.insert(7, 1);

//     std::cout << std::endl;
//     ll.printAll();

//     std::cout << std::endl;

//     std::cout << "Index of 7: " << ll.getIndex(7) << std::endl;

//     std::cout << "Value at index 1: " << ll.nodeAtIndex(1)->current << std::endl;

//     std::cout << std::endl;

//     std::cout << "Removed: " << ll.remove(10)->current << std::endl;
//     ll.printAll();

//     return 0;
// }