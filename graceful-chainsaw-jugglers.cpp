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
const int N = 505;
int t, r, b, x[505];

int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cout << printCase();
        cin >> r >> b;
        if(r < b) swap(b, r);
        if(!r || !b) {
            int ans = 0;
            FOR0(i, 10000) {
                if(i * (i + 1) / 2 <= r + b) ans = i; else break;
            }
            cout << ans << endl;
            continue;
        }
        memset(x, -1, sizeof x);
        int ans = 1;
        x[0] = 1; b--;
        while(1) {
            auto cur = mp(inf, -1);
            FOR(i, 0, r + 1) {
                if(x[i] + 1 <= b) {
                    if((cur.ff > i + x[i] + 1) ||
                        (cur.ff == i + x[i] + 1 && r > b)) {
                        cur.ff = i + x[i] + 1;
                        cur.ss = i;
                    }
                }
            }
            if(cur.ff != inf) {
                ans++;
                int i = cur.ss;
                r -= i;
                b -= ++x[i];
            } else break;
        }
        cout << ans << endl;
    }
}