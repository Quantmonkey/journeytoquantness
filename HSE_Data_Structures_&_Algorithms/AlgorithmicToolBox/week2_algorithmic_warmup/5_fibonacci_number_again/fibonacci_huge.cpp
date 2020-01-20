#include <iostream>
#include <vector>

long long fibonacciFast(long long n) {
    std::vector<long long> fibonacciArray;

    fibonacciArray.push_back(0);
    fibonacciArray.push_back(1);

    if (n <= 1 ) 
        return n;
    else {
        for (long long i = 2; i <= n; i++) {
            fibonacciArray.push_back(fibonacciArray[i-1] + fibonacciArray[i-2]);
        }
    return fibonacciArray[n];
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (current % m);
}

long long lengthPisanoPeriod(long long m) {
    long long previous = 0;
    long long current = 1;
    long long result = previous + current;

    for (long long i = 0; i < m*m; i++) {
        result = (previous + current) % m;
        previous = current;
        current = result;
    
        if ((previous == 0) && (current == 1)) {
            return i + 1;
        }
    }

    return 0;
}


long long fibonacciModFast(long long n, long long m) {
    long long previous = 0;
    long long current = 1;

    long long pisanoPeriod = lengthPisanoPeriod(m);
    long long remainder = n % pisanoPeriod;
    long long result = remainder; // This broke it as opposed to result = prev + current

    for (long long i = 1; i < remainder; i++) {
            result = (previous + current) % m; // This broke it overflowed without % m
            previous = current;
            current = result;
        }

    long long answer = result % m;
    
    return answer;
}

// long long get_pisano_period(long long m) {
//     long long a = 0; 
//     long long b = 1;
//     long long c = a + b;

//     for (long long i = 0; i < m * m; i++) {
//         c = (a + b) % m;
//         a = b;
//         b = c;
//         if (a == 0 && b == 1) return i + 1;
//     }
//     return 0;
// }

// long long get_fibonacci_huge(long long n, long long m) {
//     long long remainder = n % get_pisano_period(m);

//     long long first = 0;
//     long long second = 1;

//     long long res = remainder;

//     for (long long i = 1; i < remainder; i++) {
//         res = (first + second) % m;
//         first = second;
//         second = res;
//     }

//     return res % m;
// }

// void testCompareSolution() {
//     for (int n = 2; n < 100; ++n) {
//         int a = n + rand() % 100; // n + 0 - 99999
//         int b = n + rand() % 100; // n + 0 - 99999
//         if (get_fibonacci_huge_naive(a, b) != fibonacciModFast(a, b)) {
//             std::cout << "\n\nOne of the answers is wrong!\n" <<
//                          "The fast solution's answer was: " << fibonacciModFast(a, b) << "\n" <<
//                          "But the slow solution's answer was: " << get_fibonacci_huge_naive(a, b) << "\n" <<
//                          "The first variable, n was: " << a << "\n" <<
//                          "The second variable, m was: " << b << "\n\n";
//         }
//         else {
//             std::cout << "\n\nFast solution and the slow solution is the same!\n\n";
//         }
//     }
// }


int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacciModFast(n, m) << '\n';
    // testCompareSolution();
}
