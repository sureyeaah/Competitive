#include <iostream>
#define FOR(i,j, n) for (int i = j; i < n; i++)
using namespace std;

int geti() {
  char c;
  int ret = 0;
  bool start = false;
  while(true) {
    c = getchar();
    if((c- '0' < 0 || c- '0' > 9) && !start){
      continue;
    }
    if((c-'0' < 0 || c -'0' > 9) && start){
      break;
    }
    if(start) ret *= 10;
    start = true;
    ret += c-'0';
  }
  return ret;
}

int main() {
  int h,m,ans; string s;
  h = geti();
  m = geti();
  while(!(h==0 && m==0)) {
    h = h%12;
    ans = abs(h*30000 - m*5500);
    ans = min(360000-ans,ans);

    printf("%.3f\n",(float)ans/1000);

    h = geti();
    m = geti();
  }
}