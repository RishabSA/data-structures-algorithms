#include <iostream>
#include <vector> // Have to use vector for dynamic "arrays" with non-static lengths

template <typename T> class Heap {
public:
    Heap() {
        // Get parent index: (index − 1) / 2
        // Get left child index: 2 * index + 1
        // Get right child index: 2 * index + 2

        length = 0;
    };

    int getLength() { return length; };

    std::vector<T> getHeap() { return heap; };
    
    void PrintHeap() {
        std::cout << "Heap: ";
        for (int x : heap) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    };

    // O(log(n))
    void Add(T value) {
        // Adding the value at the end is O(1)
        heap.push_back(value);
        length++;

        // Resorting the heap is O(log(n))
        MinHeapify();
    };

    void MinHeapify() {
        int i = length - 1; // Start with last inserted element
        // Starting at the lowest children in the heap, check if they are less than parents
        while ((i > 0) && (heap[i] < heap[(i - 1) / 2])) {
            // Swap with parent which moves it upwards
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    };

    int FindIndex(T value) {
        int index = 0;
        for (int x : heap) {
            if (x == value) return index;
            index++;
        }
        return -1;
    };

    bool Remove(T value) {
        int index = FindIndex(value);
        if (index < 0) return false;

        heap[index] = heap.back();
        heap.pop_back();
        length--;

        int i = index;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if (left >= length) break;  // No children

            // Get the smaller child
            int smallest = left;
            if (right < length && heap[right] < heap[left]) {
                smallest = right;
            }

            if (heap[i] <= heap[smallest]) break;

            std::swap(heap[i], heap[smallest]);
            i = smallest;
        }

        return true;
    };

    bool Contains(T value) {
        int start = 0;
        int nodes = 1;

        while (start < length) {
            start = nodes - 1;
            int end = nodes + start;
            int count = 0;

            while (start < length && start < end) {
                if (value == heap[start]) {
                    return true;
                } else if (value > heap[(start - 1) / 2] && value < heap[start]) {
                    count++;
                }
                start++;
            }

            if (count == nodes) {
                return false;
            }
            nodes *= 2;
        }

        return false;
    };

private:
    std::vector<T> heap;
    int length;
};

int main() {
    Heap<int> heap;

    heap.Add(3);
    heap.Add(9);
    heap.Add(12);
    heap.Add(7);
    heap.Add(1);

    std::cout << "The heap has " << heap.getLength() << " elements." << "\n";
    heap.PrintHeap();

    if (heap.Remove(9)) {
        std::cout << "Successfully removed 9." << "\n";
    } else {
        std::cout << "Failed to remove 9." << "\n";
    }

    if (heap.Remove(4)) {
        std::cout << "Successfully removed 4." << "\n";
    } else {
        std::cout << "Failed to remove 4." << "\n";
    }

    std::cout << "The heap has " << heap.getLength() << " elements." << "\n";
    heap.PrintHeap();

    if (heap.Contains(3)) {
        std::cout << "The heap contains 3." << "\n";
    } else {
        std::cout << "The heap does not contain 3." << "\n";
    }

    if (heap.Contains(9)) {
        std::cout << "The heap contains 9." << "\n";
    } else {
        std::cout << "The heap does not contain 9." << "\n";
    }

    return 0;
}