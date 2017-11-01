#include <iostream>
using namespace std;
int main() {
  int n, s, t, p[100000];
  scanf("%d%d%d", &n, &s, &t);
  for(int i = 0; i < n;i++) {
    scanf("%d", &p[i]);
  }
  int c = s;
  int a = 0;
  while(c != t) {
    c = p[c-1];
    if(c == s){cout << -1 << endl; return 0;}
    a++;
  }
  cout << a <<endl;
}
