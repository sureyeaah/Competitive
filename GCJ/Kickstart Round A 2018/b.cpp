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
const ld EPS = 1e-20, PI = acosl(-1.0);
const int N = 2e4 + 5;
int t, v[N], k, n;
ll dp[N];
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> n >> k;
        FOR0(i, n) cin >> v[i];
        sort(v, v + n, greater<int>());
        dp[0] = v[0];
        FOR(i, 1, n) dp[i] = dp[i-1] + v[i];
        long double e = dp[n-1] / ((long double)n);
        int piv = -1;
        if(k) {
            // int l = 0, r = n - 1, ans=0;
            // while(l <= r) {
            //     int mid = (l + r) >> 1;
            //     if(dp[mid] - (mid+1)*e < EPS) {
            //         r = mid - 1;
            //     } else {
            //         ans = mid;
            //         l = mid + 1;
            //     }
            // }
            // e = max(e + (dp[ans] - (ans + 1)*e) / n, e);
            P<long double,int> ee = mp(e, -1);
            FOR0(i, n) {
                ee = max(ee, mp(e + (dp[i] - (i+1)*e) / n, i));
            }
            e = ee.ff; piv = ee.ss;
            k--;
        }
        while(k--) {
            long double ee = e;
            FORD(i, 0, piv+1) {
                if(ee < e + (dp[i] - (i+1)*e) / n) {
                    piv = i;
                    ee = e + (dp[i] - (i+1)*e) / n;
                } else break;
            }
            if(ee < e) {
                piv = -1;
                ee = e;
            }
            e = ee;
        }
        cout << printCase() << setprecision(10) << fixed << e << endl;
    }
}