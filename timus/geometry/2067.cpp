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
#define N 200005
struct point {
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        return (other.x == x && y < other.y) || (x < other.x);
    }
};
bool sameLine(point a, point b, point c) {
    return 1LL * (a.y - b.y) * (a.x - c.x) == 1LL * (a.y - c.y) * (a.x - b.x);
}
int main() {
    SYNC
    int n; point p[N];
    cin >> n;
    FOR0(i, n) cin >> p[i].x >> p[i].y;
    bool ans = 1;
    FOR(i,2,n) ans &= sameLine(p[0], p[1], p[i]);
    cout << ans << endl;
    if(ans) {
        int l = 0, r = 0;
        FOR0(i, n) {
            if(p[i] < p[l]) l = i;
            if(p[r] < p[i]) r = i;
        }
        cout << l+1 << " " << r+1 << endl;
    }
}