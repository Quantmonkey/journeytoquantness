/* Looking for patterns

f0 = 0        = 0
f1 = 1        = 1
f2 = 0 + 1    = 1 = f0 + f1
f3 = 1 + 1    = 2 = f1 + f2
f4 = 1 + 2    = 3 = f2 + f3
f5 = 2 + 3    = 5 = f3 + f4
f6 = 3 + 5    = 8 = f4 + f5


S0: f0                           =  f0          = 0
S1: f0 + f1                      =  S0 + f1     = 0 + 1    = 1
S2: f0 + f1 + f2                 =  S1 + f2     = 1 + 1    = 2
S3: f0 + f1 + f2 + f3            =  S2 + f3     = 2 + 2    = 4
S4: f0 + f1 + f2 + f3 + f4       =  S3 + f4     = 4 + 3    = 7
S5: f0 + f1 + f2 + f3 + f4 + f5  =  S4 + f5     = 7 + 5    = 12
Sn: f0 + f1 +      ...     + fn  =  Sn-1 + fn
*/

/* 
Attempt 1
Fast solution, but sadly not fast enough. Took 2.2 seconds for n = 832564823476

int fibonacciFast(long long n) {
    std::vector<long long> fibonacciArray;
    std::vector<long long> fibonnaciSumArray;

    fibonacciArray.push_back(0); // f0
    fibonacciArray.push_back(1); // f1
    fibonnaciSumArray.push_back(0); // s0
    fibonnaciSumArray.push_back(1); // s1

    if (n < 2) {
        return n;
    }

    for (long long i = 2; i <= n; ++i) {
        long long iFibonacciNumber = fibonacciArray[i-2] + fibonacciArray[i-1]; // Creates the ith fibonacci number
        long long modFibonacciNumber = iFibonacciNumber % 10; // Takes the last digit of the Fibonnaci nunber
        fibonacciArray.push_back(modFibonacciNumber); // Pushes the last digit of the ith fibonacci number into the array

        long long fibonnaciSum = fibonnaciSumArray[i-1] + fibonacciArray[i]; // Creates the ith fibonacci sum of the largest digits
        long long modFibonnaciSum = fibonnaciSum % 10; // Takes the last digit of this fibonacci sum
        fibonnaciSumArray.push_back(modFibonnaciSum); // Pushes the last digit of the ith fibonacci sum into the array
    }
    return fibonnaciSumArray[n];
}
*/

/* Looking for a pattern again
f0 = 0           = f2 - f1
f1 = 1           = f3 - f2
f2 = 1 = f0 + f1 = f4 - f3 
f3 = 2 = f1 + f2 = f5 - f4
f4 = 3 = f2 + f3 = f6 - f5
f5 = 5 = f3 + f4 = f7 - f6
f6 = 8 = f4 + f5 = f8 - f7
.
.
.
fn = fn+2 - fn+1

Sn = f2 - f1 + f3 - f2 + f4 - f3 + f5 - f4 + ... + fn + 2 - fn + 1
Sn = f(n+2) - 1

Since we're only interested in the last digit
Can use Pisano period trick

We are essentially finding [F(n+2) mod 10] - 1
*/

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

#include <iostream>
#include <vector>


int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}



void testCompareSolution() {
    for (int n = 2; n < 10; ++n) {
        int a = n + rand() % 1; // n + 0 - 99999
        if (fibonacci_sum_naive(a) != fibonacciFast(a)) {
            std::cout << "\n\nOne of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << fibonacciFast(a) << "\n" <<
                         "But the slow solution's answer was: " << fibonacci_sum_naive(a) << "\n" <<
                         "The first variable, n was: " << a << "\n\n";
        }
        else {
            std::cout << "\n\nFast solution and the slow solution is the same!\n\n";
        }
    }
}



int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacciFast(n);
    // testCompareSolution();
}
