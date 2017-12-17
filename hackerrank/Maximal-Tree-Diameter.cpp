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
const int N = 5e5 + 5;
int n, a, b, ans = 0, best[N][3] = {}, longest[N] = {};
vvi g(N);
unordered_map<int, int> dep[N], path[N];
void dfs(int u = 1, int prev=0) {
  priority_queue<int, vi, greater<int>> pq, pq1;
  for(int v: g[u]) {
    if(v == prev) continue;
    dfs(v, u);
    pq.push(1 + best[v][0]);
    pq1.push(longest[v]);
    if(pq1.size() > 2) pq1.pop();
    if(pq.size() > 3) pq.pop();
    longest[u] = max(longest[u], longest[v]);    
  }
  int i = pq.size(), cur[2] = {};
  while(pq.size()) {
    best[u][--i] = pq.top();
    pq.pop();
  }
  i = pq1.size();
  while(pq1.size()) {
    cur[--i] = pq1.top();
    pq1.pop();
  }
  longest[u] = max(longest[u], best[u][0] + best[u][1]);
  for(int v : g[u]) {
    if(v == prev) continue;
    dep[u][v] = best[u][0] == 1 + best[v][0] ? best[u][1] : best[u][0];
    path[u][v] = best[u][0] == 1 + best[v][0] || best[u][1] == 1 + best[v][0] ?
                best[u][0] + best[u][1] + best[u][2] - (1 + best[v][0]): best[u][0] + best[u][1];
    path[u][v] = max(path[u][v], cur[0] == longest[v] ? cur[1]: cur[0]);
  }
}
void down(int u = 1, int prev = 0, int longesthere = -1, int use = 0) {
    if(prev) {
        ans = max(ans, 1 + longest[u] + use);
    }
    for(int v : g[u]) {
        if(v == prev) continue;
        int newlong = max(longesthere + 1, dep[u][v]);
        int newuse = max(use, max(path[u][v], 1 + longesthere + dep[u][v]));
        down(v, u, newlong, newuse);
    }
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n-1) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs();
    down();
    cout << ans;
}
