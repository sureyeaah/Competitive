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
const int inf = 1e9, mod = 998244353;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 505;
int n, k, dp[N][N][3][2], val[N][N][2], pre[N][N][2];
void add2(int &x ,int y) {x = (x + y) % mod;}
int add(int x ,int y) {return (x + y) % mod;}
int mult(int x ,int y) {return (x *1LL* y) % mod;}
int main() {
    SYNC
    cin >> n >> k;
    if(n == 1) {
        cout << (k ? 0 : 2) << endl;
        return 0;
    }
    int ans = 0;
    FOR(x, 1, n) {
        int y = (k-1)/x;
        add2(ans, mult(val[x][n-1][0] + val[x][n-1][1], pre[y][n-1][0] + pre[y][n-1][1]));
    }
    ans = mult(ans, 2);
    cout << ans;
}