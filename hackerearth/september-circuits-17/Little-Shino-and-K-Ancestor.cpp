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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 1000005
vvi g(N), par(N);
int a[N], n, k;
void dfs(int u, int prev) {
    int si = SZ(par[a[u]]);
    int ans = (si) < k ? -1: par[a[u]][si - k];
    par[a[u]].pb(u);
    for(int v : g[u]) {
        if(v == prev)
            continue;
        dfs(v, u);
    }
    par[a[u]].pop_back();
    a[u] = ans;
}
int main() {
    SYNC
    int x, y;
    cin >> n >> k;
    FOR0(i, n)
        cin >> a[i+1];
    FOR0(i, n-1) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1, 0);
    FOR(i,1,n+1)
        cout << a[i] << " ";
}