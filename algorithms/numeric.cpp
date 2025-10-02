#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    int limit = sqrt(num) + 1;
    for (int i = 2; i < limit; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

// Convert unsigned Base 10 Number to Binary
std::vector<int> toBinary(int num) {
    if (num <= 0) {
        return std::vector<int>{ 0 };
    }

    std::vector<int> binaryList;

    while (num > 0) {
        binaryList.push_back(num % 2);
        num /= 2;
    }

    std::reverse(binaryList.begin(), binaryList.end());
    return binaryList;
}

int getFactorial(int num) {
    if (num < 2) {
        return 1;
    }

    int factorial = 1;
    for (int i = 2; i < num + 1; i++) {
        factorial *= i;
    }

    return factorial;
}

int getGCD(int m, int n) {
    if (n == 0) return m;
    return getGCD(n, m % n);
}

int main() {
    std::cout << "Enter a number to check if it is prime: ";

    int num;
    std::cin >> num;
    bool numIsPrime = isPrime(num);

    if (numIsPrime) {
        std::cout << num << " is prime!" << "\n\n";
    } else {
        std::cout << num << " is not prime." << "\n\n";
    }

    std::cout << "Enter an unsigned number to get its binary counterpart: ";

    int decimalNum;
    std::cin >> decimalNum;
    std::vector<int> binaryNum = toBinary(decimalNum);

    std::cout << "Binary Representation: ";
    for (int digit : binaryNum) {
        std::cout << digit;
    }
    std::cout << "\n";

    std::cout << "Enter a number to get its factorial: ";
    std::cin >> num;
    int factorial = getFactorial(num);

    std::cout << "The factorial of " << num << " is " << factorial << "\n\n";

    int num1, num2;
    std::cout << "Enter number 1 to get its GCD: ";
    std::cin >> num1;
    std::cout << "Enter number 2 to get its GCD: ";
    std::cin >> num2;

    int gcd = getGCD(num1, num2);

    std::cout << "The GCD of " << num1 << " and " << num2 << " is " << gcd << "\n\n";
    
    return 0;
}