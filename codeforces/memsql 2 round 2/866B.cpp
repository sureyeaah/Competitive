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
#define N 100005
int n, S, s[N], a[N], b[N], x[N];
vi va, vb;
ll tot = 0, ans = 0;
void solve(vi& v, int &cur) {
    ll si = accumulate(v.begin(), v.end(), 0LL, [&](ll x, int y) {return x+s[y];}), ci = 0;
    si = si/S*S;
    tot -= si/S;
    for(; cur < SZ(v); cur++) {
        ci += s[v[cur]];
        if(ci >= si) {
            ans += 1LL * (s[v[cur]] - (ci - si)) * max(a[v[cur]], b[v[cur]]);
            s[v[cur]] = ci - si;
            if(ci == si) cur++;
            break;
        } else ans += 1LL * s[v[cur]] * max(a[v[cur]], b[v[cur]]);
    }
}
ll val(vi& v, int cur, int arr[N]) {
    ll ans = 0;
    for(; cur < SZ(v); cur++) ans += 1LL * arr[v[cur]] * s[v[cur]];
    return ans;
}
int main() {
    SYNC
    cin >> n >> S;
    FOR0(i, n) {
        cin >> s[i] >> a[i] >> b[i];
        tot += s[i];
        if(a[i] > b[i]) va.pb(i);
        else vb.pb(i);
    }
    tot = (tot - 1)/S + 1;
    sort(va.begin(), va.end(), [&](int lhs, int rhs) {return a[lhs] - b[lhs] > a[rhs] - b[rhs];});
    sort(vb.begin(), vb.end(), [&](int lhs, int rhs) {return b[lhs] - a[lhs] > b[rhs] - a[rhs];});
    int ia = 0, ib = 0;
    solve(va, ia);
    solve(vb, ib);
    ll newa = 0;
    if(tot <= 1) {
        newa = max(val(va, ia, a) + val(vb, ib, a), val(va, ia, b) + val(vb, ib, b));
    } else {
        newa = val(va, ia, a) + val(vb, ib, b);
    }
    cout << ans + newa;
}