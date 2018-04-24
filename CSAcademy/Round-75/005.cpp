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
const int N = 4e4 + 4, B = 800;
int n, q, a[N], dp[55][N], blocks, tmp[N];
int main() {
    SYNC
    cin >> n >> q;
    blocks = (n - 1) / B + 1;
    FOR0(i, n) cin >> a[i];
    FOR0(i, blocks) {
        int l = i * B, r = min(l + B - 1, n-1);
        memset(tmp, 0, sizeof tmp);
        FOR(i, l, r + 1) tmp[a[i]] = a[i];
        FOR(i, 1, N) tmp[i] = max(tmp[i-1], tmp[i]);
        FOR(j, 2, N) {
            for(int k = j; k < N; k += j)
                dp[i][j] = max(dp[i][j], tmp[k-1]%j);
            dp[i][j] = max(dp[i][j], tmp[N-1]%j);
        }
    }

    while(q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        if(k == 1) {
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        for(int L = (l-1)/B*B + B; l < L && l <= r; l++) ans = max(a[l]%k, ans);
        for(int R = r/B*B - 1; R < r && l <= r; r--) ans = max(a[r]%k, ans);
        while(l < r) {
            ans = max(ans, dp[l/B][k]);
            l += B;
        }
        cout << ans << endl;
    }
}