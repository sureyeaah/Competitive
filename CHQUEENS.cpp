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
int t, n, m, x, y;
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> m >> x >> y;
        ll tot = 0;
        FOR(i, 1, n + 1) {
            FOR(j, 1, m + 1) {
                int l1 = min(i-1, j-1);
                int l2 = min(n-i, m-j);
                int r1 = min(i-1, m-j);
                int r2 = min(n-i, j-1);
                tot += n * m - (n + m - 1 + l1 + l2+ r1 + r2);
                if(i == x && j == y) {
                    // cerr << l1 << " " << l2 << endl;
                    // cerr << r1 << " " << r2 << endl;
                    tot += 2 * ((x-1) * (n-x)  + (y-1) * (m-y)  + l1 * l2 + r1 * r2);
                    tot -= n * m - (n + m - 1 + l1 + l2+ r1 + r2);
                    tot -= n * m - (n + m - 1 + l1 + l2+ r1 + r2);
                }
            }
        }
        cout << tot << endl;
    }
}