#include <iostream>
#include <vector>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int fibonacciFast(int n) {
    std::vector<long long> fibonacciArray;

    fibonacciArray.push_back(0);
    fibonacciArray.push_back(1);

    if (n <= 1 ) 
        return n;
    else {
        for (int i = 2; i <= n; i++) {
            int moduloAdditionOfPriorTwoN = (fibonacciArray[i-1] + fibonacciArray[i-2]) % 10;
            fibonacciArray.push_back(moduloAdditionOfPriorTwoN);
        }

    return fibonacciArray[n];
    }
}

void testCompareSolution() {
    for (int n = 20; n < 40; ++n) {
        if (get_fibonacci_last_digit_naive(n) != fibonacciFast(n)) {
            std::cout << "One of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << fibonacciFast(n) << "\n" <<
                         "But the slow solution's answer was: " << get_fibonacci_last_digit_naive(n) << "\n\n";
        }
        else {
            std::cout << "Fast solution and the slow solution is the same!\n";
        }
    }
}

void testSolutionBigNumber() {
    if (fibonacciFast(237) != 7) {
        std::cout << "Fast answer is wrong!\n" <<
                    "The fast solution's answer was: " << fibonacciFast(237) << "\n" <<
                    "But the correct solution's answer was: " << 7 << "\n\n";
        }
    else if (fibonacciFast(239) != 9) {
        std::cout << "Fast answer is wrong!\n" <<
                    "The fast solution's answer was: " << fibonacciFast(239) << "\n" <<
                    "But the correct solution's answer was: " << 9 << "\n\n";
        }
    else {
        std::cout << "Fast solution and the correct solution is the same!\n";
    }
}

int main() {
    int n;
    std::cin >> n;
    int c = fibonacciFast(n);
    std::cout << c << '\n';
    // testCompareSolution();
    // testSolutionBigNumber();
    }
