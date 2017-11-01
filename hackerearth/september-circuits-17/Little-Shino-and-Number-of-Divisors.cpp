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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1000005;
const int inv2 = 500000004;
inline int mul(int x, int y) {return 1LL * x * y % mod;}
inline int add(int x, int y) {return (x+y) % mod;}
int main() {
    SYNC
    int n, a[N];
    cin >> n;
    FOR0(i, n) cin >> a[i];
    int y = 1, sq = 1;
    FOR0(i, n) {
        sq &= !(a[i]&1);
        y = mul(y, 1 + a[i]);
    }
    y = add(y, mod - sq);
    y = mul(y, inv2);
    int ans = 1;
    FOR0(i, n) {
        if(sq) ans = mul(ans, 1+add(mul(a[i], y), mul(a[i], inv2)));
        else ans = mul(ans, 1+ mul(a[i], y));
    }
    cout << ans;
}