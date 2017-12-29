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
const int N = 105;
int main() {
    SYNC
    int n, X, l[N], r[N]; long double v[N], vmax;
    cin >> n >> X >> vmax;
    FOR0(i, n) {
        cin >> l[i] >> r[i] >> v[i];
    }
    long double prod = 0;
    FOR0(i, n) prod += v[i] * (r[i] - l[i]);
    long double y = abs(prod/X);
    long double x = (vmax - y > EPS) ? pow(vmax*vmax - y*y, 0.5): 0;
    if(2*x - vmax < EPS) {
        cout << "Too hard";
    } else cout << fixed << setprecision(3)<< X/x;
}