#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
  string s;
  int n, c[5], maxN, maxP, curr;
  while(true) {
        map<string, int> m;
      maxN = 0; maxP = -1;
    cin >> n;
    if(n==0) break;
    while(n--) {
      FOR(i,0,5) c[i] = geti();
      sort(c, c+5);
      s = "";
      FOR(i,0,5) {s += to_string(c[i]);}
      curr = m[s] = (m.count(s)) ? m[s] + 1 : 1;
      if(curr == maxP) {maxN+=curr;}
      else if(curr > maxP) {maxN = maxP = curr;}
    }
    cout << maxN << endl;
  }
	return 0;
}


/*
for(map<string, int>::iterator i = m.begin(); i!= m.end(); i++) {
      cout << i->first << "---" << i->second << endl;
    }
*/