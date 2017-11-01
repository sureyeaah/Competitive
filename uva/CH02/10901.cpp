#include <iostream>
#include <queue>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int c, n, t, m, x; char ch;
    cin >> c;
    queue<int> cars[2];
    int timeArr[10000], timeDep[10000];
    while(c--){
        cin >> n >> t >> m;
        FOR0(i, m) {
            x = geti();
            ch = getchar();
            cin.ignore(6, '\n');
            if(ch == 'l') cars[0].push(i);
            else cars[1].push(i);
            timeArr[i] = x;
        }
        int cs = 0, ct = 0, nt;
        while(!cars[0].empty() || !cars[1].empty()) {
            if(cars[0].empty()) nt = timeArr[cars[1].front()];
            else if(cars[1].empty()) nt = timeArr[cars[0].front()];
            else nt = MIN(timeArr[cars[0].front()], timeArr[cars[1].front()]);
            ct = MAX(ct, nt);
            int numC = 0;
            while(!cars[cs].empty() && timeArr[cars[cs].front()] <= ct && numC < n) {
                numC++;
                timeDep[cars[cs].front()] = ct + t;
                cars[cs].pop();
            }
            ct += t;
            cs = 1 - cs;
        }
        FOR0(i, m) cout << timeDep[i] << endl;
        if(c) cout << endl;
    }
}