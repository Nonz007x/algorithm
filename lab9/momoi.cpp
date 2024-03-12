#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class GiftSet {
 private:
  int left;
  int right;
  int diff;
  bool leftMore;
  int calDiff() { return abs(this->left - this->right); }

 public:
  GiftSet(int left, int right) {
    this->left = left;
    this->right = right;
    this->leftMore = left > right;
    this->diff = calDiff();
  }
  void print() {
    cout << this->left << " " << this->right << " " << this->diff << endl;
  }
  int getLeft() { return left; }
  int getRight() { return right; }
  int getDiff() { return diff; }
  int getMore() { return leftMore ? left : right; }
  int getLess() { return leftMore ? right : left; }
};

bool compare(GiftSet *a, GiftSet *b) { return a->getDiff() > b->getDiff(); }

int main() {
  size_t n;
  cin >> n;
  vector<GiftSet *> giftSets(n);
  for (size_t i = 0; i < n; i++) {
    int firstV, secondV;
    cin >> firstV >> secondV;
    giftSets[i] = new GiftSet(firstV, secondV);
  }

  sort(giftSets.begin(), giftSets.end(), compare);
 
  // for (size_t i = 0; i < n; i++) {
  //   giftSets[i]->print();
  // }

  int momoi = 0, midori = 0;
  for (size_t i = 0; i < n; i++) {
    bool momoimore = momoi > midori;
    if (momoimore) {
      momoi += giftSets[i]->getLess();
      midori += giftSets[i]->getMore();
    } else {
      midori += giftSets[i]->getLess();
      momoi += giftSets[i]->getMore();
    }
  }
  cout << abs(momoi - midori) << endl;
  return 0;
}