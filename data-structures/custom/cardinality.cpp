#include <iostream>
#include <cmath>
#include <functional>
#include "hashes.cpp"

class LinearCounting {
public:
    int bitMapSize = 100;
    bool *bitMap;
    Hash hash = Hash();
    // std::hash<int> hash;

    LinearCounting(int m) {
        bitMapSize = m;
        bitMap = new bool[bitMapSize];
    };

    LinearCounting() {
        bitMap = new bool[bitMapSize];
    };

    void add(int data) {
        // Hash the data
        bitMap[hash.hash_data(data) % bitMapSize] = true;
        // bitMap[hash(data) % bitMapSize] = true;
    };

    int estimate() {
        int B = bitMapSize;
        int V = 0;

        for (int i = 0; i < B / sizeof(bitMap[0]); i++) {
            if (bitMap[i] == false) V++;
        }

        return (int) (-1 * B * std::log((double) V / B));
    };
};

class MinimumValues {
public:
    int kMin = 5;
    std::vector<int> kMinData;

    Hash hash = Hash();
    // std::hash<int> hash;

    MinimumValues(int k) {
        kMin = k;
    }

    MinimumValues() = default;

    void add(int data) {
        kMinData.push_back(hash.hash_data(data));

        // Re-order the vector in place so that it follows a heap where the smallest is last
        // Sorting algorithm - largest to smallest log(n)
        std::push_heap(kMinData.begin(), kMinData.end());

        // If we have exceeded the value of k, remove the largest value
        if (kMinData.size() > kMin) {
            std::pop_heap(kMinData.begin(), kMinData.end());
            kMinData.pop_back();
        }
    };

    int estimate() {
        return (kMin - 1) / ((double) kMinData[0] / hash.p3);
    };
};

class HyperLogLog {
public:
    HyperLogLog() {

    };

    void add(int data) {

    };

    int estimate() {

    };
};

int main() {
    LinearCounting LC = LinearCounting(2500);
    MinimumValues MV = MinimumValues(25);
    HyperLogLog HLL = HyperLogLog(25);

    for (int i = 0; i < 1000; i++) {
        LC.add(i);
        MV.add(i);
        HLL.add(i);
    }

    std::cout << "Estimate of unique items (Linear Counting): " << LC.estimate() << std::endl;
    std::cout << "Estimate of unique items (Minimum Values): " << MV.estimate() << std::endl;
    std::cout << "Estimate of unique items (HyperLogLog): " << HLL.estimate() << std::endl;

    return 0;
}