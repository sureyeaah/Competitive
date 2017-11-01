#include <iostream>
using namespace std;

int main() {
  int n, x, y, a, z1, z2, p;
  scanf("%d%d", &n, &x);
  z1 = x;
  z2 = 0;
  int i = 1;
  for(; i < n; i++) {
    scanf("%d", &y);
    if(x > y) {
      x = y;
      p = i;
      break;
    }
    x = y;
  }
  if(i == n) {cout << 0 << endl; return 0;}
  i++;
  for(; i < n;i++) {
    scanf("%d", &y);
    if(x > y) {
      cout << -1 << endl;
      return 0;
    }
    x = y;
  }
  z2 = x;
  if(z2 <= z1) cout << n - p << endl; else cout << -1 << endl;
  return 0;
}
