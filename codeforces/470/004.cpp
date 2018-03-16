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
string s, t;
const int N = 1e5 + 5;
int q, a, b, c, d, x[N], y[N], dp[2][N];
int right(int a[N], int lt, int rt) {
    int l = 1, r = rt - lt + 1, ans = 0;
    while(l <= r) {
        int mid = (r+l)/2;
        if(a[rt]-a[rt-mid]) r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}
int main() {
    SYNC
    cin >> s >> t >> q;
    FOR0(i, s.length()) {
        dp[0][i+1] = (s[i] > 'A') + dp[0][i];
    }
    FOR0(i, t.length()) {
        dp[1][i+1] = (t[i] > 'A') + dp[1][i];
    }
    while(q--) {
        cin >> a >> b >> c >> d;
        int s = right(dp[0], a, b), t = right(dp[1], c, d);
        int x = dp[0][b] - dp[0][a-1], y = dp[1][d] - dp[1][c-1];
        int ans = (y-x)%2==0;
        if(ans) {
            if(s<t) ans=0;
            else if(s==t) ans=x<=y && (y==0 || x>0);
            else if(x==y) ans = (s-t)%3==0;
            else if(x>y) ans = 0;
        }
        cout << ans;
    }
}