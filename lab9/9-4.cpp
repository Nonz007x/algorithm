#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { 
  int a_diff = abs(a.first - a.second);
  int b_diff = abs(b.first - b.second);
  return a_diff > b_diff; 
}

int main() {
  size_t n;
  cin >> n;
  vector<pair<int, int>> gifts(n);
  for (size_t i = 0; i < n; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    gifts[i] = make_pair(v1, v2);
  }

  sort(gifts.begin(), gifts.end(), compare);
 
  for (size_t i = 0; i < n; i++) {
    cout << gifts[i].first << " " << gifts[i].second << " ";
  }

  int person1 = 0, person2 = 0;
  for (size_t i = 0; i < n; i++) {
    if (person1 > person2) {
      
      person1 += min(gifts[i].first, gifts[i].second);
      person2 += max(gifts[i].first, gifts[i].second);
    } else {
      person2 += min(gifts[i].first, gifts[i].second);
      person1 += max(gifts[i].first, gifts[i].second);
    }
  }
  cout << abs(person1 - person2) << endl;
  return 0;
}