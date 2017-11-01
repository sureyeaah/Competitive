#include <iostream>
using namespace std;

int main() {
  char rate[100001];
  int a,l,e[100000];
  a = l = 0;
  while(rate[l] = getchar(), rate[l] != '\n') {
    if((rate[l] - '0') % 2 == 0) {
      e[a] = l;
      a++;
    }
    l++;
  }
  char last = rate[l-1];
  if(!a) {
    cout << -1 << endl;
    return 0;
  }
  bool s1 = false;
  for(int i = 0; i < a; i++) {
    if(last - rate[e[i]] > 0) {
      rate[l-1] = rate[e[i]];
      rate[e[i]] = last;
      s1 = true;
      break;
    }
  }
  if(!s1) {
    rate[l-1] = rate[e[a-1]];
    rate[e[a-1]] = last;
  }
  for(int i = 0; i < l; i++){
    printf("%c", rate[i]);
  }
  return 0;
}
