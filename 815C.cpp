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
#define INF ((ll)1e15)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 505
int n, b, c[maxn], d[maxn], x[maxn], subsz;
ll dp1[maxn][maxn], dp2[maxn][maxn];
vvi g(maxn);
vi vec[maxn];
void dfs(int u) {
    int largest = 0;
    for(int v : g[u]) {
        dfs(v);
        sbsz[u] += sbsz[v];
        if(sbsz[v] > sbsz[largest]) largest = v; 
    }
    vec[u].pb(u);
    for(int v : g[u]) {
        if(v == largest) continue;
        vi temp; merge(vec[v].begin(), vec[v].end(), vec[u].begin(), vec[u].end(), temp.begin());
        vec[u] = temp;
    }
    FOR0(i, SZ(vec[u])) dp1[u][i+1] = dp1[u][i] + c[vec[u][i]];
    dp2[u][1] = c[u] - d[u];
     
    if(largest) {
        int v= largest; vi temp;
        merge(vec[v].begin(), vec[v].end(), vec[u].begin(), vec[u].end(), temp.begin());
        vec[u] = temp;
    }
}
int main() {
    SYNC;
    memset(sbsz, 1, sizeof sbsz);
    FOR0(i, maxn) FOR(j, 1, maxn) dp1[i][j] = dp1[i][j] = INF;
    FOR0(i, maxn) FOR(j, 1, maxn) dp2[i][j] = dp2[i][j] = INF;
    cin >> n >> b >> c[1] >> d[1];
    FOR(i,2,n+1) {
        cin >> c[i] >> d[i] >> x[i];
        g[x[i]].pb(i);
    }
    dfs(1);
}