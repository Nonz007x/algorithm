#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int findLines(vector<pair<int, int>> lines, const int n, const int start, const int end) {
  sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b) {
    int diff_a = abs(a.first - a.second);
    int diff_b = abs(b.first - b.second);
    return diff_a > diff_b;
  });


  for (int i = 0; i < n; i++) {
    cout << '{' << lines[i].first << ", " << lines[i].second << "} ";
  }

  cout << endl;

  int mark = start;
  for (int i = 0; i < n; i++) {
    if (lines[i].first <= mark && lines[i].second > mark && lines[i].second <= end) {
      cout << lines[i].first << " " << lines[i].second << "\n";
      mark = lines[i].second;
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> lines(n);

  for (int i = 0; i < n; i++) {
    cin >> lines[i].first >> lines[i].second;
  }
  int start, end;
  cin >> start >> end;

  findLines(lines, n, start, end);
  return 0;
}