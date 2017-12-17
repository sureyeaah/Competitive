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
ii solve(int g, int p) {
    if(p == 100) return mp(g, g);
    return mp(ceil(g*p/100.0), ceil(g*(p + 1)/100.0) - 1);
}
int main() {
    SYNC
    int g1, g2, p1, p2;
    cin >> g1 >> p1 >> g2 >> p2;
    ii a = solve(g1, p1), b = solve(g2, p2);
    int ans = 0;
    FOR(i, a.ff, 1+a.ss) {
        FOR(j, b.ff, 1 +b.ss) {
            if(j-i <= g2 - g1) ans = max(ans, j - i);
        }
    }
    cout << ans;
}