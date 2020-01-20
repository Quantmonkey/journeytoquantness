#include <iostream>
#include <cassert>
#include <vector>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.


int fibonacciNaive(int n) {
    if (n <= 1)
        return n;

    return fibonacciNaive(n - 1) + fibonacciNaive(n - 2);
}

long long fibonacciFast(int n) {
    std::vector<long long> fibonacciArray;

    fibonacciArray.push_back(0);
    fibonacciArray.push_back(1);

    if (n <= 1 ) 
        return n;
    else {
        for (int i = 2; i <= n; i++) {
            fibonacciArray.push_back(fibonacciArray[i-1] + fibonacciArray[i-2]);
        }
    return fibonacciArray[n];
    }
}

void testSolution() {
    for (int n = 0; n < 20; ++n) {
        if (fibonacciNaive(n) != fibonacciFast(n)) {
            std::cout << "One of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << fibonacciFast(n) << "\n" <<
                         "But the slow solution's answer was: " << fibonacciNaive(n) << "\n";
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    // std::cout << "fibonacciNaive: " << fibonacciNaive(n) << '\n';
    // testSolution();
    std::cout << fibonacciFast(n) << '\n';
    return 0;
}
