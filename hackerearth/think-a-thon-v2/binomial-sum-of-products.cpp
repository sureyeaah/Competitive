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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod ((int)1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1005;
inline int add(int x,int y) {return (x+y)%mod;}
inline int prod(int x,int y) {return (1LL*x*y)%mod;}
int modexp(int a, int b) {
    int res = 1;
    for(;b;b>>=1) {
        if(b&1)
            res = prod(res, a);
        a = prod(a,a);
    }
    return res;
}
int inv(int a) {
    return modexp(a, mod-2);
}
int main() {
    SYNC
    int dp[N][N] = {}, q;
    for(int i = 0; i < N; i++) {
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            dp[i][j] = add(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            dp[i][j] = i*j;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N-1; j++) {
            dp[i][j+1] = prod(dp[i][j+1], dp[i][j]);
        }
    }
    cin >> q;
    while(q--) {
        int ans = 0;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int i = a; i <= b; i++) {
            if(c) ans = add(ans, prod(dp[i][d], inv(dp[i][c-1])));
            else ans = add(ans, dp[i][d]);
        }
        if(ans < 0) ans += mod;
        cout << ans << newl;
    }
}