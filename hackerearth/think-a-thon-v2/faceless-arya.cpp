#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 505;
const int S = 1e6 + 5;
vvi facs(S);
bitset<S> bs;
int cnt = 0;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR(i, 2, S) {
        if(!bs[i]) continue;
        for(int j = i; j < S; j+=i) {
            bs[j] = 0;
            facs[j].pb(cnt);
        }
        cnt++;
    }
}
int val[2][S];
int main() {
    SYNC
    sieve();
    int t, n, m, a[N][N];
    cin >> t;
    while (t--) {
        memset(val,-1,sizeof val);
        cin >> n >> m;
        FOR0 (i, n) {
            FOR0 (j, m) {
                cin >> a[i][j];
            }
        }
        int ans, cur = 0;
        FOR(i, n-1, n) {
            ans = -1;
            FOR0(j, m) {
                int best = -1;
                for(int p : facs[a[i][j]]) {
                    best = max(best, a[i][j]);
                }
                for(int p : facs[a[i][j]]) {
                    val[cur][p] = max(val[cur][p], best);
                }
                ans = max(ans, best);
            }   
        }
        FORD(i, 0, n-1) {
            cur ^= 1;
            ans = -1;
            FOR0(j, m) {
                int best = -1;
                for(int p : facs[a[i][j]]) {
                    if(val[cur^1][p] != -1) {
                        best = max(best, val[cur^1][p] + a[i][j]);
                    }
                }
                for(int p : facs[a[i][j]]) {
                    val[cur][p] = max(val[cur][p], best);
                }
                ans = max(ans, best);
            }
            // DEBUG(ans);
            FOR0(j, m) {
                for(int p : facs[a[i+1][j]]) {
                    val[cur^1][p] = -1;
                }
            }   
        }
        if(ans == -1) {
            ans = 0;
            if(n == 1) ans = 1;
        }
        cout << ans << newl;
    }
}