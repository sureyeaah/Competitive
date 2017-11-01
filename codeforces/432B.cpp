#include <iostream>
using namespace std;

int geti() {
  char c;
  int ret = 0;
  bool start = false, minus = false;
  while(true) {
    c = getchar();
    if((c- '0' < 0 || c- '0' > 9) && c!='-' && !start){
			continue;
		}
		if((c-'0' < 0 || c -'0' > 9) && c!='-' && start){
			break;
		}
    if(start) ret *= 10;
    start = true;
    if(c=='-') minus = true;
    else ret += c-'0';
  }
  if(!minus) return ret;
  else return -ret;
}

int main() {
  int x, a[100000],col[100000] = {};
  int n = geti();
  for(int i = 0; i < n; i++) {
    x = geti();
    a[i] = geti();
    col[x-1]++;
  }
  for(int i = 0; i < n;i++) {
    int hg = n - 1 + col[a[i]-1];
    printf("%d %d\n", hg, 2*(n-1) - hg);
  }
}
