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
const int N = 1e5 + 5;
int n;
long double a[N], b[N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n, greater<long double>());
    sort(b, b + n, greater<long double>());
    long double l = 0, r = 0, ans = 0;
    int i = 0, j = 0;
    for(;i < n; i++) {
        l += a[i];
        while(j < n && min(l, r + b[j]) - 1 >= min(l, r)) {
            r += b[j++];
        }
        ans = max(ans, min(l, r) - i - j - 1);
    }
    cout << fixed << setprecision(4) << ans;
}