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
#define maxn 200005
int n, k, q, l[maxn], r[maxn];
ll ans[maxn], ft[maxn];
void update(int i, int val) {
    while(i<=maxn) {
        ft[i] += val;
        i += i&(-i);
    }
}
ll query(int i) {
    ll ret = 0;
    while(i) {
        ret += ft[i];
        i -= i&(-i);
    }
    return ret;
}

int main() {
    SYNC;
    memset(ft,0,sizeof ft);
    cin >> n >> k >> q;
    FOR0(i, n) cin >> l[i] >> r[i];
    FOR0(i, n) {update(l[i],1); update(r[i]+1,-1);}
    FOR(i, 1, maxn) {
        int x = query(i);
        ans[i] = ans[i-1] + ((ll)(x >= k));
    }
    FOR0(i, q) {
        int a, b;
        cin >> a >> b;
        cout << ans[b] - ans[a-1] << '\n';
    }
}