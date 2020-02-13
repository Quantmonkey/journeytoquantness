#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;

  if (n <= 2) {
    summands.push_back(n);
    return summands;
  }

  bool can_breakup_prize = true;
  int sum_of_prize_pool = 0;
  int last_biggest_prize = 1;

  while (can_breakup_prize) {
    summands.push_back(last_biggest_prize); // Inserts the first prize = 1
    sum_of_prize_pool += last_biggest_prize;  // Adds the prize pool so far

    int next_increment = last_biggest_prize + 1; // The next increment
    int remainder = n - sum_of_prize_pool; 
    int next_remainder = remainder - next_increment;
    int next_next_increment = next_increment + 1;

    if (remainder < next_increment) { // Remainder being less than the next increment means that there is no possible prize bigger than the previous one
      can_breakup_prize = false; // End the while loop
      last_biggest_prize = remainder;
      summands.push_back(last_biggest_prize);
    }

    else {
      if (next_remainder < next_next_increment) {
        can_breakup_prize = false;
        last_biggest_prize = remainder;
        summands.push_back(last_biggest_prize);

      }
      else {
        last_biggest_prize += 1;
      }
    }
  }
  

  
  


  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
