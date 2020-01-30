#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(double capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> valuePerWeight;

  for (int i=0; i < weights.size(); i++) {
    valuePerWeight.push_back(values[i]/weights[i]);
  }

  while (weights.size() > 0 && capacity > 0) {
    double max = 0;
    int itemNum = 0;

    // Finding the itemNum of the highest value:weight
    for (int i=0; i < weights.size(); i++) {
      if (valuePerWeight[i] >= max) {
        max = valuePerWeight[i];
        itemNum = i;
      }
    }

    if (capacity >= weights[itemNum]) {
      capacity = (double)capacity - (double)weights[itemNum];
      value = (double)value + (double)values[itemNum];
      weights.erase(weights.begin() + itemNum);
      values.erase(values.begin() + itemNum);
      valuePerWeight.erase(valuePerWeight.begin() + itemNum);
    }

    else if (capacity <= weights[itemNum]) {
      // std::cout << "\n\nmax is:" << max << "\n\n";
      // std::cout << "itemNum is:" << itemNum << "\n\n";
      // std::cout << "weights[itemNum] is:" << weights[itemNum] << "\n\n";
      double fraction = (double)capacity / (double)weights[itemNum];
      // std::cout << "fraction:" << fraction << "\n\n";
      // std::cout << "value before:" << value << "\n\n";
      value = (double)value + (double)fraction*(double)values[itemNum];
      // std::cout << "value after:" << value << "\n\n";
      // std::cout << "capacity before:" << capacity << "\n\n";
      capacity = (double)capacity - fraction*(double)weights[itemNum];
      // std::cout << "capacity after:" << capacity << "\n\n";
      weights[itemNum] = (double)weights[itemNum] - (double)fraction*weights[itemNum];
    }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
