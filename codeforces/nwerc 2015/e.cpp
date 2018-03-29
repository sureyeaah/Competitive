// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 2505;
int n, a[N], b[N];
unordered_set<ll> s;
unordered_map<ll, int> match;
vector<ll> v[N], vis(N, 0);
int augment(int u) {
    if(vis[u]) return 0;
    vis[u] = 1;
    for(int nxt : v[u]) {
        if(match[nxt] == 0 || augment(match[nxt])) {
            match[nxt] = u; return 1;
        }
    }
    return 0;
}
int ok(int i, ll x) {
    return match[x]==i;
}
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, n+1) {
        cin >> a[i] >> b[i];
        s.insert(a[i] + b[i]);
        s.insert(a[i] - b[i]);
        s.insert(a[i] * 1LL * b[i]);
        v[i].pb(a[i] + b[i]);
        v[i].pb(a[i] - b[i]);
        v[i].pb(a[i] *1LL* b[i]);
    }
    int ans = 0;
    FOR(i, 1, n+1) {
        vis.assign(n+1, 0);
        ans += augment(i);
    }
    if(ans < n) {
        cout << "impossible"; return 0;
    }
    FOR(i, 1, n + 1) {
        char x = '*'; ll val = a[i] * 1LL * b[i];
        if(ok(i, a[i] + b[i])) x = '+', val = a[i] + b[i];
        else if(ok(i, a[i] - b[i])) x = '-', val = a[i] - b[i];
        cout << a[i] << " " << x << " " << b[i] << " = " << val << endl;
    }
}