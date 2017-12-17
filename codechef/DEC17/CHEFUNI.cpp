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
int t, x[3], a, b, c;
int val(int p) {
    if(p < 0 || p > x[0]) return inf;
    int m = min(x[0] + x[1] - 2 * p, (x[0] + x[1] + x[2] - 3 * p) / 2);
    return p * c + b * m + a * (x[0] + x[1] + x[2] - 3*p - 2 * m);
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        FOR0(i, 3) cin >> x[i];
        cin >> a >> b >> c;
        sort(x, x + 3);
        int s = x[0] + x[1] + x[2], ans = (s) * a, p = max(0, x[0] + x[1] - x[2]);
        ans = min(ans, x[0] * c + (s - 3 * x[0]) * a);
        ans = min(ans, val(0));
        ans = min(ans, val(1));
        ans = min(ans, val(p-1));
        ans = min(ans, val(p));
        ans = min(ans, val(x[0]));
        cout << ans << newl;
    }
}