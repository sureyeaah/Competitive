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
int main() {
    SYNC
    int n, p, q, r, a[N]; ll dp[N];
    cin >> n >> p >> q >> r;
    FOR0(i, n) cin >> a[i];
    if(1) {
        ll curMax[3] = {(ll)-4e18,(ll)-4e18,(ll)-4e18};
        FOR0(i, n) {
            curMax[0] = max(curMax[0], 1LL * a[i] * p);
            curMax[1] = max(curMax[1], curMax[0] + 1LL * a[i] * q);
            curMax[2] = max(curMax[2], curMax[1] + 1LL * a[i] * r);
            
            
            dp[i] = curMax[2];
        }
    }
    cout << dp[n-1] << endl;
}