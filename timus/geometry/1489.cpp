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
    int x, y, z;
    point() {x = y = z = 0;}
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
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
ll sq(int x)  {return 1LL * x * x;}
long double dist(point p1, point p2) {
    return pow((long double)sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z), 0.5)/100.0;
}
int a, b, c;
void movePoint(point& p) {
    if(p.x < c) {
        // if(p.x < 0 || p.y < b + c || p.y > 2*b + c) return;
        p.z = c - p.x;
        p.x = c;
    } else if (p.x > c+a) {
        // if(p.x > 2*c + a || p.y < b + c || p.y > 2*b + c) return;
        p.z = p.x - a - c;
        p.x = c + a;
    } else if(p.y <= b) {
        // if(p.y < 0 || p.x < c || p.x > a + c) return;
        p.z = c;
        p.y = b + c + b - p.y;
    } else if (p.y < c+b) {
        // if(p.x < c || p.x > a + c) return;
        p.z = c - p.y + b;
        p.y = b + c;
    } else if(p.y > 2*b + c) {
        // if(p.y > 2 * (b + c) || p.x < c || p.x > a + c) return;
        p.z = p.y - 2*b - c;
        p.y = 2*b + c;
    }
}
int getdist() {
    int x, y; char c;
    cin >> x >> c >> y;
    return x*100 + y;
}
void print(point p1) {
    cout << p1.x << " " << p1.y << " " << p1.z << endl;
}
int main() {
    SYNC
    point p1, p2;
    cin >> a >> b >> c;
    p1.x = getdist();
    p1.y = getdist();
    p2.x = getdist();
    p2.y = getdist();
    a*= 100;
    b*= 100;
    c*= 100;
    movePoint(p1); movePoint(p2);
    // print(p1);
    // print(p2);
    cout << fixed << setprecision(10) << dist(p1, p2);
}