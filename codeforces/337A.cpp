#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int n, m, x, diff;
  int sizes[51];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &sizes[i]);
  }
  sort(sizes, sizes+m);
  diff = sizes[n-1] - sizes[0];
  for(int i = 1; i < m - n + 1;i++) {
    int currDiff = sizes[i+n-1] - sizes[i];
    if(currDiff < diff) {
      diff = currDiff;
    }
  }
  cout << diff << endl;
}
