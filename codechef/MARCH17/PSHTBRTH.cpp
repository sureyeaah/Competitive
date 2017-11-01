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
#define maxn 100005
int g[(1 << 16) + 5], ft[maxn], cnt[(1 << 16) + 5][5][5] = {};
int recurse(int x) {
    if(g[x] != -1) return g[x];
    bitset<300> bs;
    FORD(r, 0, 4)  {
        FORD(c, 0, 4) {
            cnt[x][r][c] = cnt[x][r+1][c] + cnt[x][r][c+1] - cnt[x][r+1][c+1] + ((x & (1 << (r*4 + c))) != 0);
        }
    }
    FOR0(r1,4) FOR0(c1,4) FOR0(r2,r1+1) FOR0(c2,c1+1) {
        if((r1-r2+1)*(c1-c2+1) != (cnt[x][r2][c2] + cnt[x][r1+1][c1+1] - cnt[x][r2][c1+1] - cnt[x][r1+1][c2])) continue;
        int y = x;
        FOR(r,r2,r1+1) FOR(c,c2,c1+1) y ^= (1 << (4*r + c));
        bs[recurse(y)] = 1;
    }
    g[x] = 0;
    while(bs[g[x]]) g[x]++;
    return g[x];
}
int getcake() {
    int ret = 0; char x;
    FOR0(i, 16) {
        cin >> x;
        if(x == '1') ret |= 1 << (i);
    }
    return ret;
}
int t, n, m;
void update(int i, int val) {
    while(i <= n) {
        ft[i] ^= val;
        i += i & (-i);
    }
}
int query(int i) {
    int ret = 0;
    while(i) {
        ret ^= ft[i];
        i -= i & (-i);
    }
    return ret;
}
int main() {
    SYNC
    int type, l, r;
    FOR0(i, 1 << 16) g[i] = -1; g[0] = 0;
    recurse((1 << 16) - 1);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        memset(ft,0,sizeof ft);
        FOR(i,1,n+1) update(i, g[getcake()]);
        while(m--) {
            cin >> type;
            if(type == 1) {
                cin >> l >> r;
                cout << ((query(r)^query(l-1)) ? "Pishty\n": "Lotsy\n");
            } else {
                cin >> l;
                update(l, g[getcake()]^query(l)^query(l-1));
            }
        }
    }
}