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
  vector<int> platforms(n, 0);
  int platformCount = 1;
  int process = 0;
  bool created;
  for (int i = 0; i < n; i++) {
    created = false;
    for (int j = 0; j < platformCount; j++) {
      if (ad_times[i].first >= platforms[j]) {
        process++;
        created = true;
        platforms[j] = ad_times[i].second;
        break;
      }

    }
    if (!created && platformCount < 3) {
      process++;
      platformCount++;
      platforms[i] = ad_times[i].second;
    }
  }
  
  cout << process << "\n";
  return platformCount;
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