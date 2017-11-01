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
#define N 100001
long double p[N], ans = 0;
vvi g(N);
void dfs(int u, int prev, long double prob, int dep) {
    int cnt = 0;
    for(int v : g[u]) {
        if(v == prev) continue;
        cnt++;
    }
    for(int v : g[u]) {
        if(v == prev) continue;
        dfs(v, u, prob/cnt, dep + 1);
    }
    if(!cnt) ans += prob*dep;
}
int main() {
    SYNC
    p[0] = 1;
    int n, u, v;
    cin >> n;
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0, 1, 0);
    cout << fixed << setprecision(14) << ans;
}