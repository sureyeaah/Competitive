#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int n, m, x, y, status[16], pieces[16][2];
bool found;
// status: 0 - not used, 1 - simple pos, 2 - inverted
void backtrack(int prev, int k) {
    if(found) return;
    if(k == n) {
        if(pieces[prev][2 - status[prev]] == pieces[m+1][0]) found = true;
    } else if(!found){
        FOR(i,1,m+1) {
            if(!status[i]) {
                if(pieces[i][0] == pieces[prev][2-status[prev]]) {
                    status[i] = 1;
                    backtrack(i, k+1);
                    status[i] = 0;
                    if(found) break;
                }
                else if(pieces[i][1] == pieces[prev][2-status[prev]]) {
                    status[i] = 2;
                    backtrack(i, k+1);
                    status[i] = 0;
                    if(found) break;
                }
            }
        }
    }
}

int main(){
    while(true) {
        cin >> n;
        if(!n) break;
        cin >> m;
        cin >> pieces[0][0] >> pieces[0][1];
        cin >> pieces[m+1][0] >> pieces[m+1][1];
        FOR(i,1,m+1) {
            cin >> pieces[i][0] >> pieces[i][1];
        }
        found = false;
        memset(status, 0, sizeof(status));
        status[0] = status[m+1] = 1;
        backtrack(0, 0);
        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}