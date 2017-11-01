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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 100005
const ll mod = ((ll)1e9) + 7
int n, p, x[maxn];
ll dp1[maxn][2];
bitset<maxn> b;
vvi g(maxn);
void dfs(int u) {
    dp2[u] = 1;
    for(int v : g[u]) {
        dfs(v);
        if(b[v]) {
            cnt++;
            prod[u] = (prod[u] * ) % mod;
        }
    }

}
int main() {
    SYNC;
    cin >> n;
    FOR0(i, n-1) {
        cin >> p;
        g[p].pb(i+1);
        //g[i+1].pb(p);
    }
    FOR0(i, n) cin >> x[i];
    dfs(0);
}