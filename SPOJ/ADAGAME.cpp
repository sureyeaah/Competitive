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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 10001
#define maxm 103
int ten[4] = {1,10,100,1000};
inline int nxt (int x, int i) {
    return x + ((x%(10*ten[i])-x%(ten[i]) == 9*ten[i]) ? -9*ten[i]: ten[i]);
}
int main() {
    SYNC
    int t, n, m, dp1[maxm][maxn] = {}, dp2[maxm][maxn];
    FOR(j,0,maxn) dp1[0][j] = dp2[0][j] = j; 
    FOR(i,1,maxm) {
        FOR(j,0,maxn) {
            dp2[i][j] = INF;
            FOR0(k, 4) dp1[i][j] = max(dp1[i][j], dp2[i-1][nxt(j,k)]);
            FOR0(k, 4) dp2[i][j] = min(dp2[i][j], dp1[i-1][nxt(j,k)]);
        }
    }
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << (dp1[m][n] > n ? "Ada\n": "Vinit\n");
    }
}