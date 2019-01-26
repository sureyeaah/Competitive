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
const int N = 105, M = 50000 + 5;
int t, n, w[N], h[N], p;
ld dp[N][M];
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cout << printCase();
        cin >> n >> p;
        ll ans=0;
        FOR0(i, n) cin >> w[i] >> h[i];
        FOR0(i, n) ans += 2*(w[i] + h[i]);
        ld out = ans;
        FOR(i, 1, n + 1) {
            int x = 2*min(w[i-1], h[i-1]);
            ld large = 2*sqrtl(w[i-1]*w[i-1] + h[i-1]*h[i-1]);
            FOR0(j, M) {
                if(j < x) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-x] + large);
                if(j <= p-ans && p-ans <= dp[i][j]) out = p;
                else if(p-ans>dp[i][j]) out = max(out, ans+dp[i][j]);
            }
        }
        cout << fixed << setprecision(10) << out << endl;
    }
}