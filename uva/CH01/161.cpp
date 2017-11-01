#include <iostream>
#include <vector>
#include <algorithm>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int geti() {
  char c;int ret = 0;bool start = false;
  while(true) {
    c = getchar();
    if((c- '0' < 0 || c- '0' > 9) && !start) continue;
    if((c-'0' < 0 || c -'0' > 9) && start) break;
    if(start) ret *= 10;
    start = true;
    ret += c-'0';
  }
  return ret;
}

int main()
{
  vector<int> v;
	//ios::sync_with_stdio(false);
  int x, num0 = 0;
  while(true) {
    do {
      x = geti();
      if(x==0) {num0++; if(v.size()) break;if(num0 == 3) break;}
      else {
        num0 = 0;
        v.push_back(x);
      }
    } while (true);
    int time = 0;
    if(num0 == 3) break;
    num0 = 0 ;
    FOR(i, v[distance(v.begin(),min_element(v.begin(), v.end()))], 18001) {
      bool allGreen = true;
      FOR0(j, v.size()) {
        if(i%(2*v[j]) >= v[j] - 5) {allGreen = false; break;}
      }
      if(allGreen) {
        time = i; break;
      }
    }
    if(time) {
      int h = time/3600;
      int m = (time-h*3600)/60;
      printf("%02d:%02d:%02d\n", h, m, time-h*3600-m*60);
    } else cout << "Signals fail to synchronise in 5 hours" << endl;
    v.clear();
  }
}
