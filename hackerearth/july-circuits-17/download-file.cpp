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
#define N 100005
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
int n, s; ll t[N], d[N];
ll a = 1e6, b = 1, dp[N] = {};
void solve() {
    FOR(i, 1, n + 1) {
        dp[i] = dp[i-1] + d[i]*(t[i + 1] - t[i]);
    }
    FOR(i, 1, n + 1) {
        int x = lower_bound(dp + i, dp + n + 1, dp[i-1] + s) - dp;
        int val = s - dp[x-1] + dp[i-1];
        ll aa = d[x]*(t[x] - t[i]) + val, bb = d[x];
        ll g = gcd(aa, bb); aa /= g; bb /= g;
        if(a*bb > b*aa) {
            a = aa; b = bb;
        }
    }
}
int main() {
    SYNC
    cin >> n >> s;
    FOR0(i, n) cin >> t[i + 1] >> d[i + 1];
    t[n + 1] = 3e6 + 5;
    solve();
    reverse(t + 1, t + n + 2);
    reverse(d + 1, d + n + 1);
    transform(t + 1, t + n + 2, t + 1, [&](ll x) {return 3e6 + 5 - x;});
    solve();
    cout << a << "/" << b;
}