#include <iostream>
#include <queue>
#include <stack>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if(c==EOF) break;if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int N, x, y;
    while(true) {
        bool pqb = true, qb = true, sb = true;
        N = geti();
        if(!N) break;
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        FOR0(n,N){
            scanf("%d %d", &x, &y);
            if(x==1) {
                if(pqb)pq.push(y);
                if(qb)q.push(y);
                if(sb)s.push(y);
            } else{
                if(pqb) {
                    if(pq.empty()) pqb = false;
                    else {
                        if(pq.top() != y) pqb = false;
                        pq.pop();
                    }
                }
                if(qb) {
                    if(q.empty()) qb = false;
                    else {
                        if(q.front() != y) qb = false;
                        q.pop();
                    }
                }
                if(sb) {
                    if(s.empty()) sb = false;
                    else {
                        if(s.top() != y) sb = false;
                        s.pop();
                    } 
                }
            }
            
        }
            if((sb && (pqb || qb)) || (pqb && qb)) cout << "not sure\n";
            else if(sb) cout << "stack\n";
            else if(pqb) cout << "priority queue\n";
            else if(qb) cout << "queue\n";
            else cout << "impossible\n";
    }
}