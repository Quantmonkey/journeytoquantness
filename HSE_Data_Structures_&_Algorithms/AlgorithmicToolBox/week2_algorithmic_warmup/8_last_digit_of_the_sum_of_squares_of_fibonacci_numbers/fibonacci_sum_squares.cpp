#include <iostream>
#include <vector>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

/*
For any sum of squared fibonacci numbers up to n,
the series sumOf(Fi^2) is given by fn*fn+1
*/
long long fibonacciFast(long long n);

long long fibonacciSum(long long n) {

    long long lastDigitOfFn = fibonacciFast(n);
    long long lastDigitOfFnPlusOne = fibonacciFast(n+1);
    long long answer = (lastDigitOfFn * lastDigitOfFnPlusOne) % 10;
    
    return answer;
}

// F(n+2) % 10 - 1
long long fibonacciFast(long long n) {
    long long pisanoPeriod = 60;
    long long previous = 0;
    long long current = 1;
    long long answer;

    long long remainder = (n) % pisanoPeriod;
    long long result = remainder;

    // Getting F(remainder)
    for (long long i = 1; i < remainder; i++) {
            result = (previous + current) % 10; // This broke it overflowed without % m
            previous = current;
            current = result;
        }

    long long fRemainder = result;
    long long fibN = fRemainder % 10;
    
    return fibN;
}

void testCompareSolution();

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacciSum(n);
    // testCompareSolution();
}

void testCompareSolution() {
    for (int n = 2; n < 10; ++n) {
        int a = n + rand() % 1; // n + 0 - 99999
        if (fibonacci_sum_squares_naive(a) != fibonacciSum(a)) {
            std::cout << "\n\nOne of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << fibonacciSum(a) << "\n" <<
                         "But the slow solution's answer was: " << fibonacci_sum_squares_naive(a) << "\n" <<
                         "The first variable, n was: " << a << "\n\n";
        }
        else {
            std::cout << "\n\nFast solution and the slow solution is the same!\n\n";
        }
    }
}