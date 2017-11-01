#include <iostream>
#include <stack>
#include <queue>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int set, n, s, Q, q, x;
    queue<int> b[101];
    stack<int> cc;
    set = geti();
    while(set--) {
        n = geti(); s = geti(); q = geti();
        int t = 0, cs = 1;
        FOR(i,1,n) {
            Q=geti();
            while(Q--) {
                x = geti();
                b[i].push(x);
            }
        }
        FOR(i,n,n+1) {
            cin >> Q;
            while(Q--) {
                cin >> x;
                b[i].push(x);
            }
        }
        bool allDone = false;
        while(true) {
            while (!cc.empty() && (cc.top() == cs || b[cs].size() < q)) {
                if(cc.top() != cs) {
                    b[cs].push(cc.top());
                }
                cc.pop();
                t++; 
            }
            while (!b[cs].empty() && cc.size() < s) {
                cc.push(b[cs].front()); b[cs].pop(); t++;
            }
            allDone = cc.empty();
            if(allDone) {
                FOR(i, 1, n+1) {
                   if(!b[i].empty()) {allDone = false; break;}
                }
            }
            if(allDone) break;
            cs = ((cs) % n) + 1;
            t += 2;
        }
        cout << t << endl;       
    }
}