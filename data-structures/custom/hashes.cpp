#include <iostream>
#include <chrono>

/*
Notes:

Hashes are a one-way computation function.

They take a piece of data and encode it into another one-way piece of code. (Encode it into another block of data)
When given only the encoded data, it is impossible to reliably recover the original data.
Hashes are used for cryptography, hashmaps, uniqueness, counting, similarity, sorting, searching, etc

Hash functions can produce the same hashed output given different inputs
*/

class Hash {
public:
    // Implements a simple hash function with 3 large prime numbers
    int hash_data(int data) {
        int a = (data + p1) % p3;
        int b = (p2 % p3);
        int c = (b * b) % p3;

        return (a * c) % p3;
    };

    double rand() {
        auto now = std::chrono::high_resolution_clock::now();
        int ns = (int) std::chrono::duration_cast<std::chrono::nanoseconds>(
            now.time_since_epoch()
        ).count();
        count++;

        return hash_data(ns + count) / (double) p3;
    };

    double rand(int seed) {
        count = seed;
        count++;

        return hash_data(count) / (double) p3;
    };

    int hash_str(const std::string& s) {
        int sum = 0;

        // Numeric representation of characters
        for (char c : s) sum += c;

        return hash_data(sum);
    }
private:
    // Large prime numbers
    const int p1 = 4474087;
    const int p2 = 1813391;
    const int p3 = 3903299;

    int count = 0;
};

// int main() {
//     Hash hash = Hash();

//     std::cout << "Random double: " << hash.rand() << std::endl;
//     std::cout << "Random double: " << hash.rand() << std::endl;

//     std::cout << std::endl;

//     std::cout << "Random double with seed 42: " << hash.rand(42) << std::endl;
//     std::cout << "Random double with seed 42: " << hash.rand(42) << std::endl;

//     std::cout << std::endl;

//     std::cout << "Hello world hashed: " << hash.hash_str("hello world") << std::endl;
//     std::cout << "Hello world hashed: " << hash.hash_str("testing123") << std::endl;

//     return 0;
// }