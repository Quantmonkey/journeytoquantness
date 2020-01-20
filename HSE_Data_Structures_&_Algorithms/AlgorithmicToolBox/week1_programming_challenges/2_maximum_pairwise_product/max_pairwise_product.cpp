#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

// int naiveMaxPairwiseProduct(const std::vector<int>& numbers);
// int fastMaxPairwiseProduct(const std::vector<int>& numbers);

// void stressTesting() {
//     int i = 0;
//     int numberOfTests = 100;

//     while (i<numberOfTests) {
//         ++i;

//         int numberOfIntegers = rand() % 10 + 2; // vector_size is in the ranges of 2 - 11
//         std::cout << "No. of integers in array: " << numberOfIntegers << "\n";
        
//         std::vector<int> testInputVector;
//         for (int i=0; i<numberOfIntegers; ++i) {
//             int random_int = rand() % 10000; // an integer between 0 - 99999
//             testInputVector.push_back(random_int); 
//             std::cout << "Int inserted into vector: " << random_int << "\n";
//         }
        
//         std::cout << "\n";

//         long long naiveResult = naiveMaxPairwiseProduct(testInputVector);
//         long long fastResult = fastMaxPairwiseProduct(testInputVector);

//         if (naiveResult != fastResult) {
//             std::cout << "Difference between answers!\n" << "naiveResult: " << naiveResult 
//                       << "\nfastResult: " << fastResult << "\n";
//             break;
//         }
//         else {
//             std::cout << "No difference between naive and fast results so far\n\n";
//         }
//     }
// }

// int naiveMaxPairwiseProduct(const std::vector<int>& numbers) {
//     int max_product = 0;
//     int n = numbers.size();

//     for (int first = 0; first < n; ++first) {
//         for (int second = first + 1; second < n; ++second) {
//             max_product = std::max(max_product,
//                 numbers[first] * numbers[second]);
//         }
//     }

//     return max_product;
// }

// int fastMaxPairwiseProduct(const std::vector<int>& numbers) {
//     std::vector<int> heapArray = numbers;
    
//     std::make_heap(heapArray.begin(), heapArray.end());

//     int highest_number = heapArray.front();

//     std::pop_heap(heapArray.begin(),heapArray.end()); heapArray.pop_back();

//     int second_highest_number = heapArray.front();
//     int max_product =  highest_number * second_highest_number;

//     return max_product;
// }

long long MaxPairwiseProduct(std::vector<int>& heapArray) {
    
    std::make_heap(heapArray.begin(), heapArray.end()); // O(n)

    long long highest_number = heapArray.front();

    std::pop_heap(heapArray.begin(),heapArray.end()); heapArray.pop_back(); // O(lg(n))

    long long second_highest_number = heapArray.front();
    long long max_product =  highest_number * second_highest_number;

    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
