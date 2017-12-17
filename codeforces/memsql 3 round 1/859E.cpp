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
#define mod 1000000007
#define N 100005
bitset<N*2> empty, vis;
vvi g(N*2), fg(N*2);
int n, a[N], b[N];
int dfs(int u) {
    vis[u] = 1;
    int ans = 1;
    for(int v : g[u]) {
        ans = (ans + dfs(v)) % mod;
    }
    return ans;
}
vi vec;
int cycle(int u) {
    vis[u] = 1;
    vec.pb(u);
    for(int v : fg[u]) {
        if(vis[v]) {
            FOR0(i, SZ(vec)) if(vec[i] == v) return SZ(vec) - i;
            return 1;
        } else return cycle(v);
    }
    return 1;
}
int main() {
    SYNC
    
    empty.set();
    cin >> n;
    int ans = 1;
    FOR0(i, n) {
        cin >> a[i] >> b[i];
        empty[a[i]] = 0;
        g[b[i]].pb(a[i]);
        fg[a[i]].pb(b[i]);
    }
    FOR(i, 1, n + n + 1) {
        if(empty[i]) {
            ans = 1LL * ans * dfs(i) % mod;
        }
    }
    FOR0(i, n) {
        if(!vis[a[i]]) {
            vec.clear();
            ans = 1LL * ans * min(cycle(a[i]), 2) % mod;
        }
    }
    cout << ans;
}