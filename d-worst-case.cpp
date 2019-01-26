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
ll pos(ll i, ll a, ll b, ll x) {
    if(i > b-1 || i < 1) return 1;
    return i * (a+x+1-i) < a*b;
}
ll bs(ll a, ll b) {
    ll ans=0, l = 1, r = b-1;
    while(l<=r) {
        ll x = (l + r) >> 1;
        ll i = (a + x + 1)/2;
        if(pos(i, a, b, x) && pos(i+1, a, b, x) && pos(i-1, a, b, x))
            ans = x, l = x + 1;
        else r = x - 1;
    }
    return ans;
}
int main() {
    SYNC
    int q;
    ll a, b;
    cin >> q;
    while(q--) {
        cin >> a >> b;
        // if(a == 1 || b == 1) {
        //     a==b ? 
        // }
        ll ans = 0;
        ll ar = bs(b, a);
        ll br = bs(a, b);
        ans += ar + br;
        ans += min(b-br-1, a-ar-1);
        cerr << ar << " " << br << endl;
        cout << ans << endl;
    }
}