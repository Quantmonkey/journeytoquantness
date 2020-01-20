#include <iostream>

int gcdNaive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

long long gcdFast(int a, int b) {
  if (b == 0) 
    return a;
  long long aModb = a % b;

  return gcdFast(b, aModb);
}

void testCompareSolution() {
    for (int n = 20; n < 40; ++n) {
        int a = n + rand() % 100;
        int b = n + rand() % 100;
        if (gcdNaive(a, b) != gcdFast(a, b)) {
            std::cout << "One of the answers is wrong!\n" <<
                         "The fast solution's answer was: " << gcdFast(a, b) << "\n" <<
                         "But the slow solution's answer was: " << gcdNaive(a, b) << "\n\n";
        }
        else {
            std::cout << "Fast solution and the slow solution is the same!\n";
        }
    }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcdFast(a, b) << std::endl;
  return 0;
}
