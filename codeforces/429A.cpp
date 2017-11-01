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
#define N 100005
vvi g(N);
int goal[N] = {}, init[N] = {}, cnt[N] = {};
bitset<N> flip;
void dfs(int u, int p, int pp) {
    flip[u] = (cnt[pp] & 1)^(init[u] != goal[u]);
    cnt[u] = cnt[pp] + flip[u];
    for(int v : g[u]) {
        if(v != p) dfs(v,u,p);
    }
}
int main() {
    SYNC
    int n, u, v;
    cin >> n;
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    FOR0(i, n) cin >> init[i+1];
    FOR0(i, n) cin >> goal[i+1];
    flip[0] = 0;
    dfs(1,0,0);
    cout << flip.count() << '\n';
    FOR(i,1,n+1) if(flip[i]) cout << i << '\n';
}