#include <iostream>

bool isPalindrome(std::string word) {
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    int left = 0;
    int right = word.size() - 1;
    while (word[left] == word[right] && left < right) {
        left++;
        right--;
    }

    return word[left] == word[right];
}

int main () {
    std::string word;
    std::cout << "Enter a word to check if it is a palindrome: ";
    std::cin >> word;

    bool wordIsPalindrome = isPalindrome(word);
    if (wordIsPalindrome) {
        std::cout << word << " is a palindrome!" << "\n";
    } else {
        std::cout << word << " is not a palindrome." << "\n";
    }

    return 0;
}