// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);

int main() {
    SYNC
    int n, N=0, m, x;
    cin >> n;
    ld tot = 0;
    vector<long double> v, u, dp;
    FOR0(i, n) {
        cin >> m;
        N += m;
        ld s = 0;
        FOR0(j, m) {
            cin >> x;
            tot += x;
            s += x;
            v.push_back(x);
        }       
        s /= m;
        u.push_back(s);
    }
    sort(v.begin(), v.end());
    for(auto x : v) {
        dp.push_back(dp.size() ? dp.back() + x: x);
    }
    ld ans = 1e18;
    for(auto x : u) {
        auto i = lower_bound(v.begin(), v.end(), x) - v.begin();
        ans = min(tot - 2 * (i ? dp[i-1]: 0) + x * (2*i - N), ans);
    }
    cout << fixed << setprecision(10) << ans;
}
