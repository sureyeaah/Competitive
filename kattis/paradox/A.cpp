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
    point operator + (point other) {
        return point(x + other.x, y + other.y);
    }
    point operator - (point other) {
        return point(x - other.x, y - other.y);
    }
};
long double dist(point p1, point p2) { return hypot(p1.x - p2.x, p1.y - p2.y);}
point rotate(point p, long double theta) {
    long double rad = theta * PI / 180;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

int main() {
    SYNC
    int n; string s, inst;
    point p[25];
    while(cin >> n && n) {
        getline(cin, s);
        point ans;
        FOR0(i, n) {
            getline(cin, s);
            istringstream iss(s);
            iss >> p[i].x >> p[i].y;
            long double ang = 0.0, val;
            while(iss >> inst) {
                iss >> val;
                if(inst[0] == 'w') {
                    p[i] = rotate(point(val,0.0), ang) + p[i];
                } else ang += val;
            }
            ans = ans + p[i];
        }
        long double worst = -1;
        ans.x /= n; ans.y /= n;
        FOR0(i, n) worst = max(worst, dist(ans, p[i]));
        cout << fixed << setprecision(6) << ans.x << " " << ans.y << " " << worst << newl;

    }
}