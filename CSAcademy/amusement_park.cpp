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
const int N = 1005;
int T, a, p[N][N];
long double e[N][N] = {};
int main() {
    SYNC
    cin >> T >> a;
    FOR(i, 1, T + 1) {
        FOR0(j, a) {
            cin >> p[i][j];
        }
    }
    FOR(t, 1, T + 1) {
        long double x = 0, y = 1;
        FOR0(i, a) {
            int nxt = i + 1; if(nxt == a) nxt = 0;
            x = x + y * (1 + e[t-1][nxt] * (1 - p[t][i]/100.0));
            y *= p[t][i]/100.0;
        }
        e[t][0] = x/(1-y);
        FORD(i, 1, a) {
            int nxt = i + 1; if(nxt == a) nxt = 0;
            e[t][i] = (1 + e[t-1][nxt] * (1 - p[t][i]/100.0)) + e[t][nxt] * p[t][i]/100.0;
        }
    }
    cout << fixed << setprecision(10) << e[T][0];
}