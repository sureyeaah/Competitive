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
const int N = 18, M = 1 << N;
int n; ld dp[M][N], p[N][N];
inline int isset(int mask, int i) {return mask & (1 << i);}
int main() {
    SYNC;
    cin >> n;
    FOR0(i, n) {
        FOR0(j, n) {
            cin >> p[n-i-1][n-j-1];
        }
    }
    n--;
    if(!n) {
        cout << fixed << setprecision(10) << 1; return 0;
    }
    int mask = (1 << n) - 1;
    FOR0(i, n) {
        dp[mask][i] = p[n][i];
    }
    mask--;
    for(; mask; mask--) {
        for(int i = 0; i < n; i++) {
            if(!isset(mask, i)) continue;
            for(int j = 0; j < n; j++) {
                if(isset(mask, j)) continue;
                int mask1 = mask | (1 << j);
                dp[mask][i] = max(dp[mask][i], dp[mask1][i] * p[i][j] + dp[mask1][j] * p[j][i]);
            }
        }
    }
    ld ans = 0;
    FOR0(i, n) ans = max(ans, dp[1 << i][i]);
    cout << fixed << setprecision(10) << ans << endl;
}
