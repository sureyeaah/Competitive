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
#define N 200005
int n, q, p[N], ft[N] = {};
ll cnt[N]= {};
void update(int i, int val) {
    for(;i < N; i+=i&-i)
        ft[i] += val;
}
int query(int i) {
    int ans = 0;
    for(;i;i-=i&-i)
        ans += ft[i];
    return ans;
}

ll c2(int x) {
    return (1LL * x * (x-1)) >> 1;
}
int main() {
    SYNC
    cin >> n >> q;
    FOR0(i, n) cin >> p[i+1];
    vii v[N], vv[N];
    FOR(qq, 1, q+1) {
        int l, d, r, u;
        cin >> l >> d >> r >> u;
        cnt[qq] = c2(l-1) + c2(n - r) + c2(d - 1) + c2(n - u);
        v[r+1].pb(mp(u, -qq));
        v[r+1].pb(mp(d-1, qq));
        vv[l-1].pb(mp(u, -qq));
        vv[l-1].pb(mp(d-1, qq));
    }
    FORD(qq, 1, n+1) {
        update(p[qq], 1);
        for(auto cur : v[qq]) {
            if(cur.ss > 0) cnt[cur.ss] -= c2(query(cur.ff));
            else cnt[-cur.ss] -= c2(query(n) - query(cur.ff));
        }
    }
    memset(ft, 0, sizeof ft);
    FOR(qq, 1, n+1) {
        update(p[qq], 1);
        for(auto cur : vv[qq]) {
            if(cur.ss > 0) cnt[cur.ss] -= c2(query(cur.ff));
            else cnt[-cur.ss] -= c2(query(n) - query(cur.ff));
        }
    }
    FOR(qq, 1, q+1) {
        cout << c2(n) - cnt[qq] << '\n';
    }
}