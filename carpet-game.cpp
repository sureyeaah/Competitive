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
const int N = 2e5;
int d, n, m; ll k;
int fac[N];
int main() {
    SYNC
    fac[0] = 0;
    FOR(i, 1, N) fac[i] = fac[i-1]*1LL*i % mod;
    cin >> d;
    while(d--) {
        cin >> n >> m >> k;
        int ans = 0;
        ans = ans + m*1LL*max(0,n-k+1) % mod;
        ans = ans + n*1LL*max(0,m-k+1) % mod;
        ans = ans + max(0,n-k+1)*2LL*max(0,m-k+1) % mod;
        
        if(k<N) ans = ans * 1LL * fac[k] % mod;
        cout << ans << endl;
    }
}