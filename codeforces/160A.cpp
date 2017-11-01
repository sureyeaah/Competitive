// http://codeforces.com/problemset/problem/160/A

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int array[100];
  int total = 0;
  int myValue = 0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> array[i];
    total += array[i];
  }
  int coinsLeft = n;
  sort (array, array+n);

  for (; myValue <= total/2; coinsLeft--) {
    myValue += array[coinsLeft - 1];
  }

  cout << n - coinsLeft << endl;
  return 0;
}
