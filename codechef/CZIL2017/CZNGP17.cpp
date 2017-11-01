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
const int N = 2e5 + 5;
const int P = 175;
const int LOGN = 20;
int a[N], par[N], n, cnt = 0, st[N], table[N][LOGN],nd[N], euler[N], depth[N] = {}, ft[N][2][P] = {};
vvi g(N);
vii facs[1005];
void process()
{
  int i, j;
  memset(table, -1, sizeof table);
//the first ancestor of every node i is T[i]
  for (i = 2; i < cnt; i++)
      table[i][0] = par[i];

//bottom up dynamic programing
  for (j = 1; 1 << j < cnt; j++)
     for (i = 0; i <= cnt; i++)
         if (table[i][j - 1] != -1)
             table[i][j] = table[table[i][j - 1]][j - 1];
}
int lca(int p, int q)
  {
      int tmp, log, i;
   
  //if p is situated on a higher level than q then we swap them
      if (depth[p] < depth[q])
          tmp = p, p = q, q = tmp;
  
  //we compute the value of [log(depth[p)]
      for (log = 1; 1 << log <= depth[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (depth[p] - (1 << i) >= depth[q])
              p = table[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (table[p][i] != -1 && table[p][i] != table[q][i])
              p = table[p][i], q = table[q][i];
   
      return par[p];
  }
void sieve() {
    const int SZ = 1005; int pri = 0;
    bitset<SZ> isPrime;
    isPrime.set(); isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < SZ; i++) {
        if(isPrime[i]) {
            pri++;
            for(int j = i; j < SZ; j += i) {
                isPrime[j] = 0;
                int cur = j, cnt = 0;
                while(cur % i == 0) {
                    cnt++;
                    cur /= i;
                }
                facs[j].pb(mp(pri, cnt));
            }
        }
    }
}
void dfs(int u, int prev) {
    st[u] = ++cnt;
    euler[cnt] = u;
    depth[u] = depth[prev] + 1;
    for(int v : g[u]) {
        if(v == prev) continue;
        par[v] = u;
        dfs(v, u);
    }
    nd[u] = ++cnt;
    euler[cnt] = u;
}
void update(int u, int j, int val) {
    int sig = val >= 0 ? 1 : -1;
    for(auto cur : facs[abs(val)]) {
        for(int i = u; i <= cnt; i+=i&-i) {
            ft[i][j][cur.ff] += sig*cur.ss;
        }
    }
}
void update(int u, int x) {
    update(st[u], depth[u] & 1, x*a[u]);
    update(nd[u], depth[u] & 1, -x*a[u]);
}
int query(int u, int v, int type) {
    int cur[P] = {};
    int l = lca(u, v), dist = depth[v] +depth[u] - 2*depth[l];
    // DEBUG(l);
    int i = st[u], j = (depth[u] & 1)^(type==3);
    for(;i;i-=i&-i) {
        FOR0(p, P) {
            cur[p] += ft[i][j][p];
        }
    }
    i = st[l];
    for(;i;i-=i&-i) {
        FOR0(p, P) {
            cur[p] -= ft[i][j][p];
        }
    }
    i = st[v], j = (depth[v] & 1) ^ (dist&1) ^ (type==3);
    for(;i;i-=i&-i) {
        FOR0(p, P) {
            cur[p] += ft[i][j][p];
        }
    }
    i = st[l];
    for(;i;i-=i&-i) {
        FOR0(p, P) {
            cur[p] -= ft[i][j][p];
        }
    }
    if(((depth[u] - depth[l]) & 1) ^ (type == 2)) {
        for(auto x : facs[a[l]]) {
            cur[x.ff] += x.ss;
        }
    }
    return (int)accumulate(cur, cur + P, 1LL, [&](ll x, int y){return (x*(1 + y)) % mod;});
}
int main() {
    SYNC
    sieve();
    int u, v, q, type;
    cin >> n;
    FOR(i,1,n+1) cin >> a[i];
    FOR0(i, n-1) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 0);
    process();
    FOR(u,1,n+1) {
        update(u, 1);    
    }
    // cout << query(5, 4, 2) << newl;
    cin >> q;
    while(q--) {
        cin >> type >> u >> v;
        if(type == 1) {
            update(u, -1);
            a[u] = v;
            update(u, 1);
        } else cout << query(u, v, type) << newl;
    }
}