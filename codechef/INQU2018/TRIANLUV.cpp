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
const int inf = 1e9; const ll mod = 1e9 + 7, INV = 0.5e9 + 4;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
int t; ll x1, x2, x3, Y1, Y2, Y3, a, b, c;
ll add(ll a, ll b) {return (a+b) % mod;}
ll mul(ll a, ll b) {return a * b % mod;}
ll c2(ll a) {return mul(a, mul(a-1, INV));}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> x1 >> Y1;
        cin >> x2 >> Y2;
        cin >> x3 >> Y3;
        ll ans = 1;
        a = (-1 + __gcd(abs(x1-x2), abs(Y1-Y2))) % mod;
        b = (-1 + __gcd(abs(x1-x3), abs(Y1-Y3))) % mod;
        c = (-1 + __gcd(abs(x3-x2), abs(Y3-Y2))) % mod;
        // cerr << a << b << c << endl;;
        ans = add(ans, mul(a, mul(b,c)));
        ans = add(ans, mul(a, add(c2(c), c2(b))));
        ans = add(ans, mul(b, add(c2(a), c2(c))));
        ans = add(ans, mul(c, add(c2(a), c2(b))));
        ans = add(ans, mul(2,a));
        ans = add(ans, mul(2,b));
        ans = add(ans, mul(2,c));
        ans = add(ans, c2(a));
        ans = add(ans, c2(b));
        ans = add(ans, c2(c));
        ans = add(ans, mul(3, mul(a, b)));
        ans = add(ans, mul(3, mul(c, b)));
        ans = add(ans, mul(3, mul(a, c)));
        ans = add(ans, mod);
        cout << ans << endl;
    }
}