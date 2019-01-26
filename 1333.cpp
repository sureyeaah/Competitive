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
struct point {
    long double x, y;
    point() {x = y = 0.0;}
    point(long double _x, long double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(abs(x - other.x) > EPS)
            return x < other.x;
        else return y < other.y;
    }
    bool operator == (point other) const {
        return abs(x - other.x) <= EPS && abs(y - other.y) <= EPS;
    }
};
// euclidean distance
long double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y);}
int main() {
    SYNC
    int n; point p[15]; long double r[15];
    cin >> n;
    FOR0(i, n) cin >> p[i].x >> p[i].y >> r[i];
    
}