// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
int t, r, c, h, v, grid[105][105], tot;
int cnt(int r1, int r2, int c1, int c2) {
    int ret=0;
    FOR(i, r1, r2+1) FOR(j, c1, c2+1) ret += grid[i][j];
    return ret;
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cout << printCase();
        cin >> r >> c >> h >> v;
        tot = 0;
        FOR0(i, r) {
            FOR0(j, c) {
                char x; cin >> x;
                grid[i][j] = x=='@';
                tot += grid[i][j];
            }
        }
        if(tot % ((h+1) * (v+1))) {cout << "IMPOSSIBLE" << endl; continue;}
        int k = tot / (h + 1);
        int cur = 0, ans=1;
        V<int> rs{-1}, cs{-1};
        FOR0(i, r) {
            cur += accumulate(grid[i], grid[i] + c, 0);
            if(cur > k) ans = 0;
            else if(cur == k) {
                
                rs.pb(i);
                cur = 0;
            }
        }
        k = tot / (v + 1), cur = 0;
        FOR0(j, c) {
            FOR0(i, r)
                cur += grid[i][j];
            if(cur > k) ans = 0;
            else if(cur == k) {
                cs.pb(j);
                cur = 0;
            }
        }
        k /= h+1;
        FOR(i, 1, SZ(rs)) {
            FOR(j, 1, SZ(cs)) {
                if(cnt(rs[i-1]+1, rs[i], cs[j-1]+1, cs[j]) != k)
                    ans=0;
            }
        }

        cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
}