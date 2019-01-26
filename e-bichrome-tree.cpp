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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 1005
#define X 5005
int n, p, x[N], dp[N][2] = {}, src[X] = {}, ans = 1;
bitset<X> poss;
vvi g(N);
int dfs(int u) {
    poss.reset(); poss[0] = 1;
    for(int v : g[u]) {
        dfs(v);
        dp[u][1] += dp[v][0];
        FORD(i,x[v],x[u]+1) {
            if(poss[i-x[v]]) {
                poss[i] = 1;
                src[i] = v;
            }
        }
    }
    FORD(i,0,x[u]) {
        if(poss[i]) {
            dp[u][0] = x[u];
            while(src[i]) {
                dp[u][1] += -dp[src[i]][0] + dp[src[i]][1];
                src[i] = src[i - x[src[i]]];
            }
            break;
        }
    }
}
int main() {
    SYNC
    
    cin >> n;
    FOR(i,2,n+1) {
        cin >> p;
        g[p].pb(i);
    }
    FOR0(i, n) cin >> x[i+1];
    dfs(1);
    DEBUG(dp[1][0]);
    DEBUG(dp[1][1]);
    DEBUG(dp[2][0]);
    DEBUG(dp[2][1]);
    DEBUG(dp[3][0]);
    DEBUG(dp[3][1]);

    cout << (ans ? "POSSIBLE" : "IMPOSSIBE");
}