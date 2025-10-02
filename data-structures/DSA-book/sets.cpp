#include <iostream>
#include <set> // Sets are built in to most languages by default
#include <iterator>

int main() {
    // Sets automatically sort themselves
    // Cannot modify items in the set once they are added

    std::set<int> a = {2, 1, 3};
    std::set<int> b = {6, 9, 2};

    // O(N)
    std::cout << "Set A: ";
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Set B: ";
    for (int x : b) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    // O(log(N)
    a.insert(4);
    b.insert(4);

    std::set<int>::iterator a1 = a.begin();
    std::set<int>::iterator b1 = b.begin();

    std::cout << "First element in set A: " << *a1 << "\n";
    std::cout << "First element in set B: " << *b1 << "\n";

    std::set<int>::iterator a3 = next(a1, 2);
    std::set<int>::iterator b3 = next(a1, 2);

    std::cout << "Third element in set A: " << *a3 << "\n";
    std::cout << "Third element in set B: " << *b3 << "\n";

    std::cout << "\n";

    // O(log(N)
    b.erase(6);

    std::cout << "Set A: ";
    for (int x : a) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Set B: ";
    for (int x : b) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::set<int> union_set;
    std::set<int> intersection_set;

    // Set Union
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::inserter(union_set, union_set.begin()));

    // Set Intersection
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(intersection_set, intersection_set.begin()));

    std::cout << "Union: ";
    for (int x : union_set) { 
        std::cout << x << " ";
    }
    std::cout << "\n";

    std::cout << "Intersection: ";
    for (int x : intersection_set) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}