#include <iostream>
#include <functional>

int main() {
    std::string test_string = "hello world";
    std::hash<std::string> string_hash_function;
    size_t hashed_string = string_hash_function(test_string);

    std::cout << "Hash of \"" << test_string << "\": " << hashed_string << std::endl;

    int test_int = 67;
    std::hash<int> int_hash_function;
    size_t hashed_int = int_hash_function(test_int);

    std::cout << "Hash of " << test_int << ": " << hashed_int << std::endl;

    return 0;
}