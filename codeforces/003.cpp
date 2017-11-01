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
int par[N];

int findSet(int u) {
    return par[u] == u ? u : (par[u] = findSet(par[u]));
}
void unite(int u, int v) {
    int x=  findSet(u), y = findSet(v);
    par[x] = y;
}
int main() {
    SYNC
    int n, a[N], x[N];
    cin >> n;
    FOR0(i, n) par[i] = i;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) x[i] = i;
    sort(x, x + n, [&](int lhs, int rhs) {return a[lhs] < a[rhs];});
    FOR0(i, n) {
        unite(x[i], i);
    }
    vvi g(N);
    FOR0(i, n) {
        int x = findSet(i);
        g[x].pb(i);
    }
    int ans = 0;
    FOR0(i, n) if(SZ(g[i])) ans++;
    cout << ans << endl;
    FOR0(i, n) {
        if(SZ(g[i])) {
            cout << SZ(g[i]) << " ";
            for(int x : g[i]) cout << x+1 << " ";
            cout << endl;
        }
    }
}