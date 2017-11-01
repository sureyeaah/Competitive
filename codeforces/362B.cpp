#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int d[3000], n, m, c;
  c = 1;
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d", &d[i]);
  }
  sort(d,d+m);
  if(d[0] == 1 || d[m-1] == n) {
    cout << "NO" << endl;
    return 0;
  }
  for(int i = 0; i < m-1; i++) {
    if(c == d[i+1]) {cout << "NO" << endl; return 0;}
    int gap = d[i+1] - d[i];
    if(gap == 1) c = d[i+1] + 1;
    else c = d[i] + 1;
    if(c == n) { cout << "YES" << endl; return 0;}
  }
  cout << "YES" << endl;
}
