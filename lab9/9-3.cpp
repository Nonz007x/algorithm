#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool leastDeptTime(pair<double, double> a, pair<double, double> b) {
  return a.second < b.second;
}

int buildPlatform(vector<pair<double, double>> ad_times, const int n) {
  
  sort(ad_times.begin(), ad_times.end(), leastDeptTime);

  for (int i = 0; i < n; i++) {
    cout << '{' << ad_times[i].first << ", " << ad_times[i].second << "} ";
  }

  cout << endl;
  
  int platform = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (ad_times[j].second <= ad_times[i].first) {
        break;
      }
      if (j == i - 1) {
        platform++;
      }
    }
  }
  
  return platform;
}

int main() {
  int n;
  cin >> n;
  vector<pair<double, double>> ad_times(n);

  for (int i = 0; i < n; i++) {
    cin >> ad_times[i].first >> ad_times[i].second;
  }
  
  cout << buildPlatform(ad_times, n);
}