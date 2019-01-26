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
const int N = 2e5 + 5, L = 20;
int m, s[N], x[N], q;
int dp[N][L], a[L], b[L];
int cnt(int l, int r, int k) {
    return dp[r][k] - dp[l][k];
}
int main() {
    SYNC
    cin >> m;
    FOR0(i, m) {char c; cin >> c; s[i] = c - '0';}
    FOR(i, 1, m) x[i] = s[i] ^ s[i-1];
    FOR(i, 1, m) {
        for(int j = 0; i-(1<<j) >= 0; j++) {
            dp[i][j] = x[i] + dp[i-(1<<j)][j];
        }
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int n = r-l+1, k=0;
        for(; (1<<k) < n; k++) {}
        a[k] = b[k] = 0;
        int R = l;
        FORD(i, 0, k) {
            R += 1 << i;
            int o = cnt(l, R, i) - cnt(l, R-(1<<i), i + 1);
            a[i] = max(a[i+1] + o,
                        (1<<(k-i))-1 - (o + b[i+1])
                );
            b[i] = min(b[i+1] + o,
                        (1<<(k-i))-1 - (o + a[i+1])
                );
        }
        cout << (b[0]+1)/2 << endl;
    }
}
