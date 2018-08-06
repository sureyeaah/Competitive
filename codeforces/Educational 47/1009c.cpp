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
const int N = 1e5 + 5;
int a[N];
int main() {
    SYNC
    ll n, m, x, y=0, z=0; ld d;
    cin >> n >> m;
    ld ans = 0;
    ld r = (n%2==0) ? n/4.0: (n*n - 1) / (4.0 * n);
    while(m--) {
        cin >> x >> d;
        ans += x;
        if(d >= 0) y+=d;
        else z += d;
    }
    ans += y * ((ld)n-1)/2.0;
    ans += z * r;
    cout << fixed << setprecision(10) << ans;
}