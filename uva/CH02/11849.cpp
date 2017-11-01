#include <iostream>
#include <queue>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;

int geti() {
  char c; int ret = 0; bool start = false;
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

int main()
{
    int m, n, x, y;
    cin >> m >> n;
    while (m > 0 && n > 0)
    {
        int own = 0;
        queue<int> cd;
        FOR0(i, m)
        {
            x = geti();
            cd.push(x);
        }
        x=geti(); n--;
        while(true) {
            y = cd.front();
            while(x < y) {
                if(n) {
                    x = geti();
                    n--;
                } else break;
            }
            while(x >= y) {
                if(x==y) {own++;if(n) {
                    x = geti(); n--;
                } else break;}
                cd.pop();
                if(cd.empty()) {break;}
                y = cd.front(); 
            }
            if(!n || cd.empty()) break;
        }
        while(n--) x = geti();
        cout << own << endl;
        cin >> m >> n;
    }
}