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
#define N 200005
int n, a[N], x, y, ans[N] = {}, cnt[N] = {};
int gcd(int a, int b) {
    return b ? gcd(b, a % b): a;
}
vvi g(N), f(N);
void dfs(int u, int par, int curG, int d) {
    ans[u] = 1;
    for(int fac : f[a[u]]) {
        cnt[fac]++;
        if(cnt[fac] >= d-1) {ans[u] = fac;}
    }
    ans[u] = max(curG, ans[u]);
    curG = gcd(curG, a[u]);
    for(int v : g[u]) {
        if(v != par) dfs(v, u, curG, d + 1);
    }
    for(int fac : f[a[u]]) cnt[fac]--;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> a[i+1];
    FOR0(i, n-1) {
        cin >> x >> y;
        // x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j+=i) f[j].pb(i);
    }
    dfs(1, 0, 0, 1);
    FOR0(i, n) cout << ans[i+1] << " ";
}