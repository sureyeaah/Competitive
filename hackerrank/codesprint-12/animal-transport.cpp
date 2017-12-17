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
const int N = 5e4 + 5;
int cases, n, m;
vvi in(N);
struct Root {
    int t[2*N];
    int h, n;
    int d[N];
    Root() {}
    void reset() {
        memset(t, 0, sizeof t);
        memset(d, 0, sizeof d);
        n = m;
        h = sizeof(int) * 8 - __builtin_clz(n);
    }
    void apply(int p, int value) {
      t[p] += value;
      if (p < n) d[p] += value;
    }

    void build(int p) {
      while (p > 1) p >>= 1, t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
    }

    void push(int p) {
      for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
          apply(i<<1, d[i]);
          apply(i<<1|1, d[i]);
          d[i] = 0;
        }
      }
    }

    void inc(int l, int r, int value) {
      l += n, r += n;
      int l0 = l, r0 = r;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) apply(l++, value);
        if (r&1) apply(--r, value);
      }
      build(l0);
      build(r0 - 1);
    }

    int query(int l, int r) {
      l += n, r += n;
      push(l);
      push(r - 1);
      int res = -1;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res, t[l++]);
        if (r&1) res = max(t[--r], res);
      }
      return res;
    }
};
int s[N], d[N], t[N], ans[N], dp[N]; char x;
Root r[2];
int main() {
    SYNC
    cin >> cases;
    while(cases--) {
        cin >> m >> n;
        r[0].reset(); r[1].reset();
        FOR(i, 1, m + 1) in[i].clear();
        FOR0(i, n) {
            cin >> x;
            t[i] = (x=='E' || x=='C');
        }
        FOR0(i, n) cin >> s[i];
        FOR0(i, n) {
            cin >> d[i];
            if(s[i] < d[i]) {
                in[d[i]].pb(i);
            }
        }
        dp[0] = dp[1] = 0;
        memset(ans, 63, sizeof ans);
        FOR(i, 2, m + 1) {
            for(int x : in[i]) {
                r[t[x]].inc(1, s[x]+1, 1);
            }
            dp[i] = 0;
            FOR0(j, 2) {
                dp[i] = max(dp[i], r[j].query(1, i));
            }
            ans[dp[i]] = min(ans[dp[i]], i);
            r[0].inc(i, i+1, dp[i]);
            r[1].inc(i, i+1, dp[i]);
        }
        FORD(i, 1, n + 1) {
            ans[i] = min(ans[i], ans[i+1]);
        }
        FOR(i, 1, n + 1) cout << (ans[i] < inf ? ans[i]: -1) << " ";
        cout << newl;
    }

}