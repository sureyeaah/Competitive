#include <iostream>
#include <stack>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int n, x, t[1000];
    while(true) {
        n = geti();
        if(n == 0) break;
        while(true) {
            t[0] = geti();
            if(!t[0]) break;
            FOR0(i, n-1) {
                t[i+1] = geti();
            }
            stack<int> s;
            int index = n-1; int i = n;
            for(; i > 0; i--) {
                while(index >= 0) {
                    if(!s.empty() && s.top() == i) {
                        s.pop(); break;
                    }
                    s.push(t[index]); index--;
                }
                if(index < 0) break;
            }
            for(; i > 0; i--) {
                if(s.top() == i) s.pop();
                else break;
            }
            if(i) printf("No\n");
            else printf("Yes\n");
        }
        cout << endl;
    }
}