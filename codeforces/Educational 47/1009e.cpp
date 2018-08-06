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
const int inf = 1e9, mod = 998244353;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 1e6 + 5;
const inline int add(int a, int b) {return (a+b) % mod;}
const inline int mult(int a, int b) {return (a*1LL*b) % mod;}
int n, a[N];
int main() {
    SYNC
    cin >> n;
    FOR(i, 1, n+1) cin >> a[i];
    FOR(i, 1, n+1) a[i] = add(a[i], a[i-1]);
    int ans = a[n], t=1;
    FORD(r, 1, n-1) {
        ans = add(ans, mult(a[r], mult(n-r-1, t)));
        t = mult(t, 2);
    }
    t=2;
    FOR(x, 1, n) {
        ans = add(ans, mult(t, a[n-x]));
        t = mult(t, 2);
    }
    cout << ans;
}