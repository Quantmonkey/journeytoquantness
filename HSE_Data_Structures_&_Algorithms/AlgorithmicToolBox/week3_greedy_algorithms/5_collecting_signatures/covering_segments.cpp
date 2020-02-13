#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool compareInterval(Segment i1, Segment i2) 
{ 
    return (i1.end < i2.end); 
} 

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(), compareInterval);
  int furthest_mark = -1;

  for (size_t i = 0; i < segments.size(); ++i) {
    if (segments[i].start > furthest_mark) {
      
      points.push_back(segments[i].end);
      furthest_mark = segments[i].end;
      for (size_t innerIndex = 0; innerIndex < segments.size(); ++innerIndex) {
        if (segments[innerIndex].start <= segments[i].end) {
          segments[innerIndex].start = -1;
          segments[innerIndex].end = -1;
        }
      }
    }
  }

  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
