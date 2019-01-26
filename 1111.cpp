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
#define N 55
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
    point operator + (point other ) {
        return point(x + other.x, y + other.y);
    }
    point operator - (point other) {
        return point(x - other.x, y - other.y);
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
    long double operator * (point p) {
        return a * p.x + b * p.y + c;
    } 
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
long double lineDist(line l, point p) {
    return abs(l.a*p.x + l.b * p.y + l.c) / (l.a*l.a + l.b*l.b); 
}
void getSquare(point sq[4]) {
    cin >> sq[0].x >> sq[0].y;
    cin >> sq[2].x >> sq[2].y;
    sq[1] = sq[0] + rotate(sq[2] - sq[0], 45);
    sq[3] = sq[0] + rotate(sq[2] - sq[0], -45);
    sq[1].x /= pow(2, 0.5);
    sq[1].y /= pow(2, 0.5);
    sq[3].x /= pow(2, 0.5);
    sq[3].y /= pow(2, 0.5);
    // FOR0(i, 4) cout << sq[i].x << " " << sq[i].y << endl;
}
bool sameSide(line l, point a, point b) {
    return ((l * a) * (l * b)) >= 0;
}
long double sqDist(point sq[4], point p) {
    if(sq[0] == sq[1]) return dist(sq[0], p);
    long double ans = 1e9;
    int cnt = 0;
    FOR0(i, 4) {
        line l =pointsToLine(sq[i], sq[(i + 1) % 4]);
        ans = min(ans, lineDist(l, p));
        DEBUG(ans);
        if(sameSide(l, p, sq[(i + 2) % 4])) cnt ++;
    }
    return (cnt == 4 ? 0.0: ans);
}
int main() {
    SYNC
    int n, x[N]; point p[N][4], c;
    long double dist[N];
    cin >> n;
    FOR0(i, n) {
        x[i] = i;
        getSquare(p[i]);
    }
    cin >> c.x >> c.y;
    FOR0(i, n) dist[i] = sqDist(p[i], c);
    FOR0(i, n) cout << dist[i] << endl;
    sort(x, x + n, [&](int lhs, int rhs) {return dist[lhs] < dist[rhs];});
    FOR0(i, n) cout << x[i]+1 << " ";
}