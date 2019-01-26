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
int t; int a[7]; int k;
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> k;
        FOR0(i, 7) cin >> a[i];
        int tot = 0, ans = inf;
        FOR0(i, 7) tot += a[i];
        FOR0(i, 7) {
            int r = min(100, k);
            int cur = 7 * ((k-r)/tot);
            r += (k-r) % tot;
            for(int j = i; r; j++) {
                cur++;
                if(j == 7) j = 0;
                if(a[j]) r--;
            }
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
}