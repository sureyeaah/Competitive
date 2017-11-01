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
#define N 505
int n, m, type[N];
vvi g(N);
void dfs(int u, int val) {
    type[u] = val;
    for(int v : g[u]) {
        if(type[v] == -1) dfs(v, val);
    }
}
int main() {
    SYNC
    int u, v;
    memset(type, -1, sizeof type);
    cin >> n >> m;
    FOR0(i, m) {
        cin >> u >> v;
        if(u == v) continue;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR(i,1,n+1) {
        if(SZ(g[i]) == n-1) type[i] = 1;
    }
    FOR0(i, n) {
        if(type[i+1] == -1) {
            dfs(i+1, 0);
            break;
        }
    }
    FOR0(i, n) {
        if(type[i+1] == -1) {
            dfs(i+1, 2);
            break;
        }
    }
    FOR(i,1,n+1) {
        if(type[i] == -1) {
            cout << "No"; return 0;
        }
    }
    int a = count(type+1, type+1+n,0);
    int c = count(type+1, type+1+n,2);
    int b = n - a - c;
    if(a*(a-1)/2 + c*(c-1)/2 + b*(b-1)/2 + b*(a+c) != m) {
        cout << "No"; return 0;
    }
    cout << "Yes\n";
    FOR(i,1,n+1) cout << (char)('a' + type[i]);
}