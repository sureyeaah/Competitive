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
long double best = -1;
vii ans;
int n, m;
long double dist(ii a, ii b) {
    return hypot((long double)a.ff - b.ff, (long double)a.ss - b.ss);
}
int main() {
    SYNC
    cin >> m >> n;
    set<ii> pts, rem;
    pts.insert(mp(0,0));
    pts.insert(mp(m,n));
    pts.insert(mp(0,n));
    pts.insert(mp(m,0));

    pts.insert(mp(1,0));
    pts.insert(mp(0,1));
    pts.insert(mp(m-1,n));
    pts.insert(mp(m,n-1));
    pts.insert(mp(1,n));
    pts.insert(mp(0,n-1));
    pts.insert(mp(m-1,0));
    pts.insert(mp(m,1));
    for(auto p : pts) {
        if(p.ff < 0 || p.ff > m || p.ss < 0 || p.ss > n) rem.insert(p);
    }
    for(auto p : rem)
        pts.erase(p);
    vii points(pts.begin(), pts.end());
    int a = points.size();
    FOR0(i, a) {
        FOR0(j, a) {
            if(j == i) continue;
            FOR0(k, a) {
                if(k == i || k == j) continue;
                FOR0(l, a) {
                    if(l == k || l == i || l == j) continue;
                    long double cur = dist(points[i], points[j]) + dist(points[j], points[k]) + dist(points[k], points[l]);
                    if(cur > best) {
                        best = cur;
                        ans.clear();
                        ans.pb(points[i]);
                        ans.pb(points[j]);
                        ans.pb(points[k]);
                        ans.pb(points[l]);
                    }
                }
            }
        }
    }
    FOR0(i, 4) {
        cout << ans[i].ff << " " << ans[i].ss << endl;
    }
}