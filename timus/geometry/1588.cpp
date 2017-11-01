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
    int x, y;
    point() {x = y = 0;}
    point(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        return other.x == x ? y < other.y : x < other.x;
    }
};
bool coll(point a, point b, point c) {
    return 1LL * (a.y - b.y) * (a.x - c.x) == 1LL * (a.y - c.y) * (a.x - b.x);
}
long double dist(point a, point b) {
    return hypot((long double)a.x - b.x, (long double)a.y - b.y);
}
#define N 305
int main() {
    SYNC
    int n; point p[305];
    bitset<N> done[N];
    cin >> n;
    FOR0(i, n) {
        cin >> p[i].x >> p[i].y;
    }
    long double ans = 0.0;
    FOR0(i, n) {
        FOR0(j, i) {
            if(done[i][j]) continue;
            int l = i, r = i;
            vi cur;
            FOR0(k,n) {
                if(coll(p[i], p[j], p[k])) {
                    cur.pb(k);
                    if(p[k] < p[l])
                        l = k;
                    if(p[r] < p[k])
                        r = k;
                }
            }
            ans += dist(p[l], p[r]);
            FOR0(a, cur.size()) FOR0(b, cur.size())
                done[cur[a]][cur[b]] = done[cur[b]][cur[a]] = 1;
        }
    }
    cout << (int)(ans + 0.5);
}