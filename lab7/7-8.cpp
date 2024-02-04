#include <bits/stdc++.h>
#include <climits>
using namespace std;

bool isCheck(bool *bin, int n)
{
  for (int i = 0; i < n; i += 2)
  {
    if (bin[i] == bin[i + 1])
    {
      return false;
    }
  }
  return true;
}

int subset(bool *bin, int *arr, int k, int n)
{
  if (k == n)
  {
    if (isCheck(bin, n))
    {
      int bigBroSum = 0;
      int lilBroSum = 0;
      for (int i = 0; i < n; i++)
      {
        if (bin[i])
        {
          bigBroSum += arr[i];
        }
        else
        {
          lilBroSum += arr[i];
        }
      }
      return abs(bigBroSum - lilBroSum);
    }
    return INT_MAX;
  }
  else
  {
    bin[k] = true;
    int left = subset(bin, arr, k + 1, n);
    bin[k] = false;
    int right = subset(bin, arr, k + 1, n);
    return min(left, right);
  }
}

int main()
{
  int n = 4;
  int *arr = new int[n]{99, 12, 2, 5};
  bool *bin = new bool[n];
  memset(bin, false, n);
  int minDiff = subset(bin, arr, 0, n);
  cout << minDiff << endl;

  delete[] arr;
  delete[] bin;

  return 0;
}