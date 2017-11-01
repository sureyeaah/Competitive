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
#define N 105
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
// cw rotation of angle theta about origin
point rotate(point p, long double theta) {
    long double rad = theta * PI / 180;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
// ax + by + c = 0
struct line {
    long double a, b, c;
};

line pointsToLine(point p1, point p2) {
    line l;
    if(abs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = - p1.x;
    } else {
        l.a = -(long double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(long double)(l.a * p1.x) - p1.y;
    }
    return l;
}

bool areParallel(line l1, line l2 ) {
    return abs(l1.a - l2.a) < EPS && abs(l2.b - l1.b) < EPS;
}
bool sameLine(line l1, line l2) {
    return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}
long double lineDist(line l, point p) {
    return (l.a*p.x + l.b * p.y + l.c) / (l.a*l.a + l.b*l.b); 
}
point foot(line l, point p) {
    long double val = -(l.a * p.x + l.b * p.y + l.c) / (l.a*l.a + l.b * l.b);
    return point(val*l.a + p.x, val*l.b + p.y);
}
bool sameSide(line l, point a, point b) {
    return (l.a*a.x + l.b*a.y + l.c) * (l.a*b.x + l.b*b.y + l.c) >= EPS;
}
int n; point p[N], c;
bool inPolygon() {
    FOR0(i, n) {
        if(!sameSide(pointsToLine(p[i], p[i+1]), c, p[i+2])) return false;
    }
    return true;
}
int main() {
    SYNC
    cin >> c.x >> c.y >> n;
    FOR0(i, n) cin >> p[i].x >> p[i].y;
    p[n] = p[0]; p[n+1] = p[1];
    long double ans = 1e18;
    if(!inPolygon()) {
        FOR0(i, n) {
            line l = pointsToLine(p[i], p[i+1]);
            point f = foot(l, c);
            if((dist(p[i], f) + dist(f, p[i+1])-dist(p[i], p[i+1])) < EPS) ans = min(ans, 2 * dist(f, c));
            else ans = min(ans, 2*min(dist(c, p[i]), dist(c, p[i+1])));
        }
    } else ans = 0.0;
    cout << fixed << setprecision(10) << ans;
}