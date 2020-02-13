#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int find_maximum(vector<int> array);

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;

  for (size_t i = 0; i < a.size(); i++) {
    int highest_profit__click_index = find_maximum(a);
    int highest_clicks_index = find_maximum(b);
    result += ((long long) a[highest_profit__click_index]) * b[highest_clicks_index];
    a[highest_profit__click_index] = -10^5 - 1;
    b[highest_clicks_index] = -10^5 - 1;
  }

  return result;
}

int find_maximum(vector<int> array) {
  long long max = array[0];
  int maximum_index = 0;

  for (int i = 0; i < array.size(); i++) {
    if (array[i] > max) {
      max = array[i];
      maximum_index = i;
    }
  }

  return maximum_index;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
