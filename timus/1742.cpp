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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 100005;
int mina = 0, maxa = 0, cycles = 0, cycleFound = 0;
int n, g[N], vis[N] = {}, cnt[N] = {};
void dfs(int u, int v) {
    vis[u] = -1;
    if(!vis[v]) {
        dfs(v, g[v]);
    }
    if(vis[v] == -1) {
        vis[v] = 2;
        if(!cycleFound)
            cycles++;
        cycleFound = 1;
    } else {
        vis[u] = 1;
    }
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> g[i+1];
        cnt[g[i+1]]++;
    }
    FOR(i,1,n+1) {
        if(!cnt[i]) {
            cycleFound = 0;
            dfs(i, g[i]);
            mina++;
        }
    }
    FOR(i,1,n+1) {
        if(!vis[i]) {
            cycleFound = 0;
            dfs(i, g[i]);
            mina++;
        }
    }
    maxa = cycles + n - count(vis + 1, vis + n + 1, 2);
    cout << mina << " " << maxa << endl;
}