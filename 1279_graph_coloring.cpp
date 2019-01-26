// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case " << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long double ld;
typedef long long ll;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
typedef vector<int> vi;
typedef vector<vi> vvi;
int p;
int modexp(ll a, int b, int p) {
    ll ret = 1;
    for(;b;b>>=1) {
        if(b&1) ret = ret * 1LL * a % p;
        a = a * 1LL * a % p;
    }
    return ret;
}
int invmod(int x, int p) {
    return modexp(x, p-2, p);
}

inline int mul(int a, int b) {
    return a * 1LL * b % p;
}
inline int add(int a, int b) {
    return (a + b) % p;
}
int gauss(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size() - 1;
    vi where(m, -1);
    vi ans(m, 0);
    for(int row=0,col=0; row < n && col < m; col++) {
        int sel = row;
        for(int i = row; i < n; i++) {
            if(a[i][col] > a[sel][col]) sel = i;
        }
        if(!a[sel][col]) continue;
        for(int i = col; i <= m; i++)
            swap(a[row][i], a[sel][i]);
        where[col] = row;
        int inv = invmod(a[row][col], p);
        for(int i = 0; i < n; i ++) {
            if(i==row) continue;
            int f = mul(inv, a[i][col]);
            for(int j = col; j <= m; j ++) {
                a[i][j] = add(a[i][j], -mul(a[row][j], f));
                if(a[i][j] < 0) a[i][j] += p;
            }
        }
        ++row;
    }

    for(int i = 0; i < m; i ++) {
        if(where[i] != -1) ans[i] = mul(a[where[i]].back(), invmod(a[where[i]][i],p));
    }

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum = add(sum, mul(a[i][j], ans[j]));
        }
        if(sum != a[i][m]) return 0;
    }
    return modexp(p, count(where.begin(), where.end(), -1), mod);
}

int main() {
    SYNC
    int t, n, m, u, v;
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> n >> m >> p;
        vvi g(n+1);
        while(m--) {
            cin >> u >> v;
            g[u].pb(v); g[v].pb(u);
        }
        vvi mat;
        FOR(i, 1, n + 1) {
            vi v(n+1, 0);
            v[i-1]=1;
            FOR0(j, SZ(g[i])) v[g[i][j]-1]=p-1;
            mat.pb(v);
        }
        cout << printCase() << gauss(mat) << endl;
    }
}
