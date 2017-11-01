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
const int N = 2e5 + 5;
int ans = 1;
int n, m, val[N], cur[2];
int fix(int u, int x) {
    if(val[u] == -1) val[u] = x;
    else if(val[u] != x) ans = 0;
}
vvi g(N);
void dfs(int u) {
    for(int v : g[u]) {
        if(val[v] == -1) {
            val[v] = !val[u];
            cur[val[v]]++;
            dfs(v);
        } else fix(v, !val[u]);
    }
}
int main() {
    SYNC
    int a, b, c;
    cin >> n >> m;
    memset(val, -1, sizeof val);
    while(m--) {
        cin >> a >> b >> c;
        if(c==1) {
            g[a].pb(b);
            g[b].pb(a);
        } else {
            fix(a, c==2);
            fix(b, c==2);
        }
    }
    FOR(i, 1, n+1) {
        if(val[i] != -1) dfs(i);
    }
    int must = count(val + 1, val + 1 + n, 1);
    FOR(i, 1, n+1) {
        if(val[i] == -1) {
            val[i] = cur[1] = 0; cur[0] = 1;
            dfs(i);
            must += min(cur[0], cur[1]);
        }
    }
    if(ans) cout << must;
    else cout << "impossible";
}