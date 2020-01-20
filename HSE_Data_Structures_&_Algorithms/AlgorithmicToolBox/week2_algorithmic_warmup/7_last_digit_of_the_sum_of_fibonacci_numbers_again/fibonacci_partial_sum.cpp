#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long fibonacciFast(long long n) {
    long long pisanoPeriod = 60;
    long long previous = 0;
    long long current = 1;
    long long answer;

    long long remainder = (n+2) % pisanoPeriod;
    long long result = remainder;

    // Getting F(remainder)
    for (long long i = 1; i < remainder; i++) {
            result = (previous + current) % 10; // This broke it overflowed without % m
            previous = current;
            current = result;
        }

    long long fRemainder = result;
    long long fibNPlusTwoModTen = fRemainder % 10;

    if (fibNPlusTwoModTen == 0) {
        answer = 9;
    }
    else {
        answer = fibNPlusTwoModTen - 1;
    }
    
    return answer;
}

long long fibonacciPartial(long long from, long long to) {
    long long answer = 0;

    if (from <= 0) {
        answer = fibonacciFast(to);
        return answer;
    }
    else {
        long long fromLastDigit = fibonacciFast(from - 1);
        long long toLastDigit = fibonacciFast(to);

        answer = toLastDigit - fromLastDigit;
        
        if (toLastDigit < fromLastDigit) {
            answer = answer + 10;
        }

        return answer;
    }
    return answer;
}

void testCompareSolution() {
    for (int n = 2; n < 10; ++n) {
        int a = n + rand() % 10; // n + 0 - 99999
        int b = 2*n + rand() % 10; // n + 0 - 99999
        if (fibonacciPartial(a, b)!= get_fibonacci_partial_sum_naive(a, b)) {
            std::cout << "\n\nOne of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << fibonacciPartial(a, b) << "\n" <<
                         "But the slow solution's answer was: " << get_fibonacci_partial_sum_naive(a, b) << "\n" <<
                         "The first variable, n was: " << a << "\n" <<
                         "The second variable, m was: " << b << "\n\n";
        }
        else {
            std::cout << "\n\nFast solution and the slow solution is the same!\n\n";
        }
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacciPartial(from, to) << '\n';
    // testCompareSolution();
}
