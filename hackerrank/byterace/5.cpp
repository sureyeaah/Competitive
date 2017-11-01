#include <iostream>
#include <vector>
#include <cstring>
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
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if(c==EOF) break;if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int main(){
    int t, n, q, l, r, type, k, mod = 1000000007;
    scanf("%d", &t);
    while(t--) {
        long long int bombs = 0;
        n = geti(); q = geti();
        vector<long long int> bomb(n+1);
        while(q--) {
            type = geti(); l = geti(); r = geti();
            if(type == 1) {
                k = geti();
                bombs += ((long long int)(r - l + 1) * (long long int) k);
                FOR(i, l, r+1) bomb[i] += k;
            } else {
                FOR(i,l,r+1) {
                    bombs -= bomb[i];
                    bomb[i] = 0;
                }
                cout << bombs%mod << endl;
            }
        }
    }
    return 0;
}   