#include <iostream>

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

std::unordered_map is a built-in C++ hashmap implementation:

std::unordered_map<std::string, int> hashmap_name;
*/

int main () {
    std::unordered_map<std::string, int> hashmap = {{"hello world", 100}, {"testing123", 5}, {"rishab", 67}};

    // Hashmap traversal O(N)
    std::cout << "Hashmap traversal:" << std::endl;
    for (auto i : hashmap) {
        std::cout << i.first << ", " << i.second << std::endl;
    }

    // Hashmap insertion O(1)
    hashmap["zhach"] = 12;
    
    // insert() - Hashmap insertion O(1)
    hashmap.insert({"friggin packet yo", 2});

    std::cout << std::endl;

    std::cout << "Hashmap traversal (after insertion):" << std::endl;
    for (auto i : hashmap) {
        std::cout << i.first << ", " << i.second << std::endl;
    }

    std::cout << std::endl;
    
    std::cout << "Hashmap retrieval:" << std::endl;

    // Hashmap retrieval O(1)
    std::cout << hashmap["rishab"] << std::endl;
    
    // at() - Hashmap retrieval O(1)
    std::cout << hashmap.at("friggin packet yo") << std::endl;

    std::cout << std::endl;
    
    std::cout << "Hashmap element updating:" << std::endl;
    
    // Hashmap update O(1)
    hashmap["rishab"] = 69;
    std::cout << hashmap["rishab"] << std::endl;
    
    // at() - Hashmap update O(1)
    hashmap.at("friggin packet yo") = 67;
    std::cout << hashmap.at("friggin packet yo") << std::endl;

    return 0;
}