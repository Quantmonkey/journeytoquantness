#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0;
  vector<double> valuePerWeight;

  // Populating an array called valuePerWeight with ratios of value:weight
  for (int i=0; i < weights.size(); i++) {
    double valueWeightRatio = (double)values[i]/weights[i];
    valuePerWeight.push_back(valueWeightRatio);
  }

  // While there are still items to choose, and the bag is not full
  while (weights.size() > 0 && capacity > 0) {
    double max = 0;
    int itemNum;

    // Going through every item, find the item with the highest valuePerWeight and record it
    for (int i=0; i < weights.size(); i++) {
      if (valuePerWeight[i] > max) { // If an item has been found to have a valuePerWeight greater than the previous max, update the new max and item number
        max = valuePerWeight[i];
        itemNum = i;
      }
    }

    // If there is enough space in the knapsack to put the item with the highest valuePerWeight
    if (capacity >= weights[itemNum]) {
      capacity = capacity - weights[itemNum]; // Adding it to the bag, and updating the capacity and value
      value = value + values[itemNum];

      // Removing the item from the arrays to ensure that it doesn't get picked again
      weights.erase(weights.begin() + itemNum);
      values.erase(values.begin() + itemNum);
      valuePerWeight.erase(valuePerWeight.begin() + itemNum);
      max = 0;
      itemNum = 0;
    }

    // If there isn't enough space in the knapsack to put the whole item with highest valuePerWeight in
    else if (capacity < weights[itemNum]) {

      // Calculate what fraction of the item can be put in
      double fraction = (double)capacity / (double)weights[itemNum];

      // Put in that fraction of the item and update the capacity and value
      value = value + (double)fraction*values[itemNum];
      capacity = capacity - (double)fraction*weights[itemNum];

      return value;
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
  std::cout << std::setprecision(30) << optimal_value << std::endl;
  // testing_suite();
  return 0;
}

// void chooseTwoWholeItemsTest();
// void takeOneThirdTest();
// void chooseTwoWholeItemsAndOneFractionTest();

// void testing_suite() {
//   chooseTwoWholeItemsTest();
//   takeOneThirdTest();
//   chooseTwoWholeItemsAndOneFractionTest();
// }

// void chooseTwoWholeItemsTest() {
//   int capacity = 50;

//   vector<int> weights;
//   weights.push_back(20);
//   weights.push_back(50);
//   weights.push_back(30);

//   vector<int> values;
//   values.push_back(60);
//   values.push_back(100);
//   values.push_back(120);

//   std::cout << "\n\nBasic Tests: \n\n";
//   std::cout << "Capacity: " << capacity << "\n";
//   std::cout << "Weights: ";
//   for (int i = 0; i < weights.size(); i++) 
//         std::cout << weights[i] << " ";
//   std::cout << "\n";

//   std::cout << "Value: ";
//   for (int i = 0; i < values.size(); i++) 
//         std::cout << values[i] << " ";
//   std::cout << "\n";

//   double answer = get_optimal_value(capacity, weights, values);
//   if (answer != 180.0000) {
//     std::cout << "\nAlgorithm got the wrong answer!\n\n";
//     std::cout << "The correct answer is 180!\n\n";
//     std::cout << "But the algorithm's answer is: " << answer << "\n\n";
//   }
//   else {
//     std::cout << "\nAlgorithm got the correct answer!\n\n";
//   }
// }

// void takeOneThirdTest() {
//   int capacity = 10;

//   vector<int> weights;
//   weights.push_back(30);

//   vector<int> values;
//   values.push_back(500);

//   std::cout << "\n\nBasic Tests: \n\n";
//   std::cout << "Capacity: " << capacity << "\n";
//   std::cout << "Weights: ";
//   for (int i = 0; i < weights.size(); i++) 
//         std::cout << weights[i] << " ";
//   std::cout << "\n";

//   std::cout << "Value: ";
//   for (int i = 0; i < values.size(); i++) 
//         std::cout << values[i] << " ";
//   std::cout << "\n";

//   double answer = get_optimal_value(capacity, weights, values);
//   if (answer != 166.667) {
//     std::cout << "\nAlgorithm got the wrong answer!\n\n";
//     std::cout << "The correct answer is 166.667!\n\n";
//     std::cout << "But the algorithm's answer is: " << answer << "\n\n";
//   }
//   else {
//     std::cout << "\nAlgorithm got the correct answer!\n\n";
//   }
// }

// void chooseTwoWholeItemsAndOneFractionTest() {
//   int capacity = 15;

//   vector<int> weights;
//   weights.push_back(100);
//   weights.push_back(50);
//   weights.push_back(1);
//   weights.push_back(1);

//   vector<int> values;
//   values.push_back(1);
//   values.push_back(1);
//   values.push_back(100);
//   values.push_back(50);

//   std::cout << "\n\nBasic Tests: \n\n";
//   std::cout << "Capacity: " << capacity << "\n";
//   std::cout << "Weights: ";
//   for (int i = 0; i < weights.size(); i++) 
//         std::cout << weights[i] << " ";
//   std::cout << "\n";

//   std::cout << "Value: ";
//   for (int i = 0; i < values.size(); i++) 
//         std::cout << values[i] << " ";
//   std::cout << "\n";

//   double answer = get_optimal_value(capacity, weights, values);
//   if (answer != 150.26) {
//     std::cout << "\nAlgorithm got the wrong answer!\n\n";
//     std::cout << "The correct answer is 150.26!\n\n";
//     std::cout << "But the algorithm's answer is: " << answer << "\n\n";
//   }
//   else {
//     std::cout << "\nAlgorithm got the correct answer!\n\n";
//   }
// }

// void takeOneThirdTest() {
//   int capacity = 10;

//   vector<int> weights;
//   weights.push_back(30);

//   vector<int> values;
//   values.push_back(500);

//   std::cout << "\n\nBasic Tests: \n\n";
//   std::cout << "Capacity: " << capacity << "\n";
//   std::cout << "Weights: ";
//   for (int i = 0; i < weights.size(); i++) 
//         std::cout << weights[i] << " ";
//   std::cout << "\n";

//   std::cout << "Value: ";
//   for (int i = 0; i < values.size(); i++) 
//         std::cout << values[i] << " ";
//   std::cout << "\n";

//   double answer = get_optimal_value(capacity, weights, values);
//   if (answer != 166.667) {
//     std::cout << "\nAlgorithm got the wrong answer!\n\n";
//     std::cout << "The correct answer is 166.667!\n\n";
//     std::cout << "But the algorithm's answer is: " << answer << "\n\n";
//   }
//   else {
//     std::cout << "\nAlgorithm got the correct answer!\n\n";
//   }
// }