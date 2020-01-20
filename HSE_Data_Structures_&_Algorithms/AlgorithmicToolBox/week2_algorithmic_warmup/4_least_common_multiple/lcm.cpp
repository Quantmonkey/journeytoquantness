#include <iostream>

long long lcmNaive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l) // O((a*b))
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcdFast(long long a, long long b) {
  if (b == 0) 
    return a;
  long long aModb = a % b;

  return gcdFast(b, aModb); // O(lg(a+b))
}

long long lcmFast(long long a, long long b) {
  long long multiplyAB = a * b;
  long long answer = multiplyAB / gcdFast(a, b);
  return answer;
}

void testCompareSolution() {
    for (int n = 20; n < 100; ++n) {
        int a = n + rand() % 100;
        int b = n + rand() % 100;
        if (lcmNaive(a, b) != lcmFast(a, b)) {
            std::cout << "One of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << lcmFast(a, b) << "\n" <<
                         "But the slow solution's answer was: " << lcmNaive(a, b) << "\n\n";
        }
        else {
            std::cout << "Fast solution and the slow solution is the same!\n";
        }
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcmFast(a, b) << std::endl;
  // testCompareSolution();
  return 0;
}
