#include <iostream>
#include "linked_list_node.cpp"

/*
Notes:

A singly linked list is a linear collection of nodes, where each node contains data and a pointer to the next node only, allowing for forward traversal.

Access by index: O(N)
Search by value: O(N)
Insert at head: O(1)
Delete head: O(1)
Insert at tail (with tail pointer): O(1)
Delete tail (no tail pointer): O(N)
Insert after given node/iterator: O(1)
Insert before given node (with only forward links): O(N)
Delete given node when you only have its pointer: O(N)
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
        // This way is inefficient O(N)

        // Node* currentNode = head;

        // while (currentNode->next != nullptr) {
        //     currentNode = currentNode->next;
        // }

        // currentNode->next = new Node(newVal);

        length++;

        if (tail == nullptr) {
            head = new Node(newVal);
            tail = head;
            return true;
        }

        tail->next = new Node(newVal);
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

        return originalHead;
    };

    // O(N)
    Node* pop() {
        if (head == nullptr) return nullptr;

        length--;

        if (head->next == nullptr) {
            Node* removed = head;
            head = nullptr;
            tail = nullptr;

            return removed;
        }

        Node* currentNode = head;
        while (currentNode->next->next != nullptr) {
            currentNode = currentNode->next;
        }

        Node* removed = tail;

        currentNode->next = nullptr;
        tail = currentNode;

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

        if (nodeToDelete == tail) tail = currentNode;

        nodeToDelete->next = nullptr;
        return nodeToDelete;
    };
};

int main () {
    LinkedList ll = LinkedList(5);
    ll.append(10);
    ll.append(15);
    ll.append(17);

    std::cout << "Length of the linked list: " << ll.getLength() << std::endl;

    ll.printAll();

    ll.pop();

    std::cout << std::endl;
    ll.printAll();

    ll.insert(7, 1);

    std::cout << std::endl;
    ll.printAll();

    std::cout << std::endl;

    std::cout << "Index of 7: " << ll.getIndex(7) << std::endl;

    std::cout << "Value at index 1: " << ll.nodeAtIndex(1)->current << std::endl;

    std::cout << std::endl;

    std::cout << "Removed: " << ll.remove(10)->current << std::endl;
    ll.printAll();

    return 0;
}