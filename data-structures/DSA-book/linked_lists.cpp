#include <iostream>
#include <memory>
#include <optional>

template <typename T> struct Node {
    T num;
    Node<T> *next = nullptr;
};

template <typename T> class LinkedList {
public:
    LinkedList() = default;
    ~LinkedList() {
        delete head;
        delete tail;
    };

    // O(1)
    bool Push(T num) {
        if (head == nullptr) {
            head = new Node<T>();
            head->num = num;

            // Keep track of the tail - last node in the linked list
            tail = head;
            length++;

            return true;
        }

        Node<T> *newNode = new Node<T>();
        newNode->num = num;

        tail->next = newNode;
        tail = newNode;
        length++;

        return true;
    };

    // O(N)
    void Display() {
        if (head == nullptr) {
            return;
        }

        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->num << " ";
            current = current->next;
        }
        std::cout << "\n";
    };

    // Given a value return the 0-based index of where it is in the list.
    // O(N)
    int Search(T num) {
        if (head == nullptr) {
            return -1;
        }

        int currentIdx = 0;

        Node<T> *current = head;

        while (current != nullptr) {
            if (current->num == num) {
                return currentIdx;
            }

            current = current->next;
            currentIdx++;
        }

        return -1;
    };

    // O(N)
    T *RemoveAtIndex(int index) {
        if (head == nullptr) {
            return nullptr;
        }

        int currentIdx = 0;

        Node<T> *current = head;
        Node<T> *previous = nullptr;

        while (current->next != nullptr) {
            if (currentIdx == index) {
                T *currentVal = &current->num;
                previous->next = current->next;

                length--;

                return currentVal;
            }

            previous = current;
            current = current->next;
            currentIdx++;
        }

        if (currentIdx == index) {
            T *currentVal = &current->num;
            previous->next = current->next;

            length--;

            return currentVal;
        }

        return nullptr;
    }

    // O(N)
    T *Pop() { return RemoveAtIndex(length - 1); }

    int getLength() { return length; }

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int length = 0;
};

int main() {
    // Create a linked list
    LinkedList<int> ll;

    ll.Push(6);
    ll.Push(10);
    ll.Push(-15);
    ll.Push(0);

    std::cout << "Length: " << ll.getLength() << "\n";

    ll.Display();

    std::cout << "\n";

    std::cout << "Index of -15: " << ll.Search(-15) << "\n";
    std::cout << "Index of 15: " << ll.Search(15) << "\n";

    // Pop Last
    auto *popValue = ll.Pop();
    if (popValue == nullptr) {
        std::cout << "Something went wrong..." << "\n";
        return 0;
    }

    std::cout << "Popped Value: " << *popValue << "\n";
    ll.Display();
    std::cout << "Length: " << ll.getLength() << "\n";

    // Remove at index 1
    auto *value = ll.RemoveAtIndex(1);
    if (value == nullptr) {
        std::cout << "Something broke..." << "\n";
        return 0;
    }

    std::cout << "Removed Value: " << *value << "\n";

    std::cout << "\n";

    ll.Display();
    std::cout << "Length: " << ll.getLength() << "\n";

    std::cout << "End of program..." << "\n";

    return 0;
}