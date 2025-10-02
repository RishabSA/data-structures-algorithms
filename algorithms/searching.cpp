#include <iostream>
#include <vector>

// O(N)
template<typename T>
int seqSearch(std::vector<T> list, T val) {
    // Loop through the list and check every item

    for (int i = 0; i < list.size(); i++) {
        if (list[i] == val) {
            return i;
        }
    }

    return -1;
}

// O(log(N))
template<typename T>
int binarySearch(std::vector<T> list, T val) {
    // Binary Search only works with a sorted list

    int mid = 0;
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (list[mid] == val) {
            return mid;
        } else if (list[mid] < val) {
            low = mid + 1;
        } else if (list[mid] > val) {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 5, 6, 7, 9, 10, 34, 50};

    int seqSearchIdx = seqSearch(nums, 10);
    std::cout << "Sequential Search found 10 at index: " << seqSearchIdx << "\n";

    int binarySearchIdx = binarySearch(nums, 10);
    std::cout << "Binary Search found 10 at index: " << binarySearchIdx << "\n";

    return 0;
}