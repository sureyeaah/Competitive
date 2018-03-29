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
ll u[10], r[10], uu[10], rr[10], tt[10];
int main() {
    SYNC
    FOR0(i, 10) cin >> u[i] >> r[i];
    FOR0(i, 10) cin >> uu[i] >> rr[i] >> tt[i];
    ll ans = 0;
    FOR0(j, 3) {
        FOR0(i, 10) {
            if(tt[i] <= ans) {
                ll done = (ans - tt[i]) / (uu[i] + rr[i]);
                done *= (uu[i] + rr[i]); done += tt[i];
                if(done + uu[i] <= ans) ans += u[i] + r[i],
                    tt[i] = max(ans - r[i], done + rr[i] + uu[i]);
                else ans = done + r[i] + uu[i] + u[i],
                    tt[i] = done + uu[i] + max(u[i] , rr[i]);
            } else {
                ans += u[i] + r[i];
                tt[i] = max(tt[i], ans - r[i]);
            }
        }
    }
    cout << ans - r[9];
}