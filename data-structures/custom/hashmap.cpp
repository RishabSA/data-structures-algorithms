#include <iostream>
#include <list>
#include "hashes.cpp"

/*
Notes:

Hash tables/hash maps are a data structure that store key-value pairs using a hashing technique.
Hash table insertion and retrieval has a time complexity of O(1)

They allow you to access elements in constant time complexity with keys, rather than a set index
Hash functions are used to convert a key into a numerical index, which can map to an index in an array where the value is stored.

The hash function can produce billions of possible hashed outputs, so instead of allocating a lot of memory, we take the modulus between the hash value and the maximum size (hash_out % max_size) and use that as the index in an array to store or access a value.
Hash functions can produce the same hashed output given different inputs and when taking the modulus between a hash output and the maximum size, this can result in more than one keys mapping to the same index, resulting in a collision.

Each bucket has an index and is a space where data can be stored. Collisions happen when moer than one key is hashed and modded, and ends up pointing to the index of the same bucket.

Collision Avoidance Methods:
- Linear Probing: Linear Probing involves linearly searching for the next open slsot in the array to put the data in. After hashing and modding, if the resulting index already has a value in it, linearly move forward to the next available index, and store or access or the data there. The correct index has been found when the values equal each other.
    - PROS: Saves memory.
    - CONS: Once all of the memory in the hashmap is used, no new items can be assigned. Also, items are constantly pushed back instead of being assigned to their natural hashed location. Also, changing the length of the hashmap to mitigate this would require completely recreating and rehashing the entire hashmap and all of its elments, which is inefficient and can create many unnecessary clusters.
- Chaining: Chaining involves turning each bucket into a linked list. When a collision occurs and more than one hashed key points to the same bucket, a linked list is created where the items are chained together. Here, the first item stores a pointer reference to the new item where both items exist in the same bucket with the same index.
    - PROS: Uses dynamic memory and each hashed and moddded output maps to its proper index in the hashmap.
    - CONS: Uses more memory.
*/

class HashmapWithoutChaining {
public:
    int* data;
    int max_size;

    HashmapWithoutChaining(int m) {
        if (m <= 0) throw std::runtime_error("Invalid hashmap size");

        max_size = m;
        data = new int[m];
    };

    HashmapWithoutChaining() {
        max_size = 1000;
        data = new int[1000];
    };

    int get_idx(const std::string& key) {
        return hash.hash_str(key) % max_size;
    };

    void add(const std::string& key, int value) {
        data[get_idx(key)] = value;
    }

    int get(const std::string& key) {
        if (data[get_idx(key)]) {
            return data[get_idx(key)];
        }

        throw std::runtime_error("Key does not exist");
    };

    int get(const std::string& key, int defaultVal) {
        if (data[get_idx(key)]) {
            return data[get_idx(key)];
        }

        return defaultVal;
    };

    ~HashmapWithoutChaining() {
        delete[] data;
    };

private:
    Hash hash = Hash();
};

class HashmapWithChaining {
public:
    std::list<std::pair<std::string,int>>* data;
    int max_size;

    HashmapWithChaining(int m) {
        if (m <= 0) throw std::runtime_error("Invalid hashmap size");

        max_size = m;
        data = new std::list<std::pair<std::string,int>>[m];
    };

    HashmapWithChaining() {
        max_size = 1000;
        data = new std::list<std::pair<std::string,int>>[1000];
    };

    int get_idx(const std::string& key) {
        return hash.hash_str(key) % max_size;
    };

    void add(const std::string& key, int value) {
        std::list<std::pair<std::string,int>>& chain = data[get_idx(key)];

        for (auto& kv : chain) {
            // Update if the key exists
            if (kv.first == key) {
                kv.second = value;
                return;
            }
        }
        
        // Otherwise append to this bucket's chain
        chain.emplace_back(key, value);
    }

    int get(const std::string& key) {
        std::list<std::pair<std::string,int>>& chain = data[get_idx(key)];

        for (auto& kv : chain) {
            if (kv.first == key) return kv.second;
        }

        throw std::runtime_error("Key does not exist");
    };

    int get(const std::string& key, int defaultVal) {
        std::list<std::pair<std::string,int>>& chain = data[get_idx(key)];

        for (auto& kv : chain) {
            if (kv.first == key) return kv.second;
        }

        return defaultVal;
    };

    ~HashmapWithChaining() {
        delete[] data;
    };

private:
    Hash hash = Hash();
};

int main() {
    HashmapWithChaining hashmap = HashmapWithChaining();

    hashmap.add("hello world", 100);
    hashmap.add("testing123", 5);
    hashmap.add("rishab", 67);

    std::cout << "Get \"hello world\" from hashmap: " << hashmap.get("hello world") << std::endl;
    std::cout << "Get \"testing123\" from hashmap: " << hashmap.get("testing123") << std::endl;
    std::cout << "Get \"rishab\" from hashmap: " << hashmap.get("rishab") << std::endl;

    std::cout << "Get \"hello\" from hashmap: " << hashmap.get("hello", -1) << std::endl;

    return 0;
}