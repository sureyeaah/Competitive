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
#define mod (1000000000 + 7)
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
int main() {
    SYNC
    ll t, x[2][3], v[2][3];
    cin >> t;
    FOR0(i, 3) cin >> x[0][i];
    FOR0(i, 3) cin >> v[0][i];
    FOR0(i, 3) cin >> x[1][i];
    FOR0(i, 3) cin >> v[1][i];
    FOR0(i, 3) x[0][i] -= x[1][i];
    FOR0(i, 3) v[0][i] -= v[1][i];
    ll num = 0, denom = 0;
    FOR0(i, 3) num += x[0][i]*v[0][i];
    FOR0(i, 3) denom += v[0][i]*v[0][i];
    long double ans = 0.0;
    if(-denom*num > 0) {
        long double tt = -((long double)num) / ((long double)denom);
        if(tt - t > EPS) tt = t;
        FOR0(i, 3) {
            ans += pow(x[0][i] + tt*v[0][i], 2);
        }
        ans = pow(ans, 0.5);
    } else ans = pow((long double)accumulate(x[0], x[0] + 3, 0LL, [&](ll x, ll y) {return x + y*y;}), 0.5);
    cout << fixed << setprecision(10) << ans;
}