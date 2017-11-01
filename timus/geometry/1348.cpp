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
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
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
double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y);}
// cw rotation of angle theta about origin
point rotate(point p, double theta) {
    double rad = theta * PI / 180;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}
// ax + by + c = 0
struct line {
    double a, b, c;
};

line pointsToLine(point p1, point p2) {
    line l;
    if(abs(p1.x - p2.x) < EPS) {
        l.a = 1.0; l.b = 0.0; l.c = - p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
    return l;
}
bool areParallel(line l1, line l2 ) {
    return abs(l1.a - l2.a) < EPS && abs(l2.b - l1.b) < EPS;
}
bool sameLine(line l1, line l2) {
    return areParallel(l1, l2) && abs(l1.c - l2.c) < EPS;
}
point intersect(line l1, line l2) {
    point p;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    p.y = (fabs(l1.b) > EPS) ? -(l1.a * p.x + l1.c): -(l2.a * p.x + l2.c);
    return p;
}
int main() {
    SYNC
    point a, b, c; double len;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> len;
    line l = pointsToLine(a, b);
    line l2;
    l2.a = l.b; l2.b = -l.a; l2.c = l.a*c.y - l.b*c.x;
    if(abs(l2.b) > EPS) {
        l2.a /= l2.b;
        l2.c /= l2.b;
        l2.b = 1.0;
    }
    point f = intersect(l, l2);
    double dmax = max(dist(c, a), dist(c,b)), dmin = min(dist(c, a), dist(c,b ));
    if(abs(dist(a,b) - dist(a,f) - dist(b, f)) < EPS) dmin = dist(f, c);
    cout << fixed << setprecision(2) << max(dmin-len, 0.0) << endl << max(dmax - len, 0.0);
}