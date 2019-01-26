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
const int N = 30000, M = 200;
int n, cnt[N+5] = {}, d;
int dp[N+5][2*M];
int go(int a, int j) {
    if(j <= 0 || a + j > N)
        return cnt[a];
    int jj = M - d + j;
    if(dp[a][jj] != -1) {
        return dp[a][jj];
    }
    int ans = 0;
    ans = max(ans, go(a + j, j - 1));
    ans = max(ans, go(a + j, j));
    ans = max(ans, go(a + j, j + 1));
    return dp[a][jj] = cnt[a] + ans;
}
int main() {
    SYNC
    cin >> n >> d;
    FOR0(i, n) {
        int p;
        cin >> p;
        cnt[p]++;
    }
    memset(dp, -1, sizeof dp);
    cout << go(0, d);
}
