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
#define pb emplace_back
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
#define maxn 100005
int n, k, ver[maxn][26], m = 0, lose[maxn] = {}, win[maxn] = {};
//bitset<maxn> lose, win;
string x;
vvi g(maxn, vi(26,0));
void add() {
    int u = 0, i = 0;
    while(g[u][x[i] - 'a'] && i < x.length()) {u=g[u][x[i] - 'a']; i++;}
    while(i < x.length()) {
        g[u][x[i] - 'a'] = ++m;
        u = m;
        i++;
    }
}
void dfs(int u) {
    int cnt = 0;
    for(int v : g[u]) {
        if(!v) continue;
        dfs(v);
        cnt++;
        if(!win[v]) win[u] = 1;
        if(!lose[v]) lose[u] = 1;
    }
    if(!cnt) lose[u] = 1;
}
int main() {
    SYNC
    cin >> n >> k;
    FOR0 (i, n) {
        cin >> x;
        add();
    }
    dfs(0);

    if(lose[0] && win[0]) cout << "First";
    else if(!win[0]) cout << "Second";
    else cout << ((k%2) ? "First": "Second");
}