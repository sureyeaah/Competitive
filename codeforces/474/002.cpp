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
const int N = 1e3 + 3;
int n, k1, k2, b[N];
P<int, int> a[N];
int main() {
    SYNC
    cin >> n >> k1 >> k2;
    FOR0(i, n) cin >> a[i].ff;
    FOR0(i, n) cin >> a[i].ss;
    multiset<int, greater<int>> b; FOR0(i, n) b.insert(abs(a[i].ff - a[i].ss));
    k1 += k2;
    while(k1) {
        int x = *(b.begin()); b.erase(b.begin());
        if(x > 0) x--;
        else x=1;
        b.insert(x);
        k1--;
    }
    ll ans = 0;
    for(int x : b) ans += x*1LL*x;
        cout << ans;
}