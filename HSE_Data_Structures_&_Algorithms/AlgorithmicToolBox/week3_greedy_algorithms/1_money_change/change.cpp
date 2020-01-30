#include <iostream>

int get_change(int m) {
  int count = 0;

  while (m > 0) {
    if (m == 0) {
      return count;
    }
    else if (m - 10 >= 0) {
      count++;
      m = m - 10;
    }
    else if (m - 5 >= 0) {
      count++;
      m = m - 5;
    }
    else {
      count ++;
      m = m - 1;
    }
  }

  return count;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
