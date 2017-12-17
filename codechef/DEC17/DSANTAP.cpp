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
const int N = 505;
const int PICK = 2, DROP = 3, MOVE = 1;
int t, n, g, b, x[N], y[N], p[N], k[N], l[N];
vi vec;
inline long double dist(int i, int j) {
    return hypot(1.0*x[i] - x[j], 1.0*y[i] - y[j]);
}
void pr(int i, int j) {
    cout << i << " " << j << newl;
}
void path() {
    for(int x : vec) {
        pr(PICK, l[x]);
    }
    for(int i : vec) {
        pr(MOVE, i);
        pr(DROP, l[i]);
        pr(PICK, k[i]);
    }
    pr(MOVE, 0);
    for(int x : vec) {
        pr(DROP, k[x]);
    }
}
int main() {
    SYNC
    cin >> t;
    srand(time(0));
    while(t--) {
        cin >> n >> g >> b >> x[0] >> y[0];
        FOR(i, 1, g + 1) cin >> p[i];
        FOR(i, 1, n + 1) {
            cin >> x[i] >> y[i] >> k[i] >> l[i];
        }
        vi v;
        int r = b/20;
        FOR(i, 1, n + 1) v.pb(i);
        random_shuffle(v.begin(), v.end());
        for(int i = 0; i < n; i+=r) {
            vec.clear();
            for(int j = i; j < n && j < i + r; j++)
                vec.pb(v[j]);
            path();
        }
        cout << 0 << newl;
    }
}