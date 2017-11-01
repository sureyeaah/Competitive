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
int m, n, k, b;
ll dp[N] = {};
vi x;
int main() {
    SYNC
    cin >> n >> m >> k;
    FOR0(i, n) {
        cin >> b;
        if(b) x.pb(i);
    }
    n = SZ(x);
    if(n < m) {
        cout << -1; return 0;
    }
    ll ans = 1e18;
    FOR0(i, SZ(x)) {
        dp[i+1] = dp[i] + x[i];
    }
    FOR(i, 1, SZ(x) - m + 2) {
        ll val  = x[i-1] + k*(1LL*x[i+m-2]*m - (dp[i+m-1] - dp[i-1]));
        ans = min(ans, val);
    }
    cout << ans; 
}