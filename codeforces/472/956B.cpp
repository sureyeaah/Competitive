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
int n, u, a[N];
int search(int l, int r, int x) {
    int ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(a[mid] - x <= u) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
int main() {
    SYNC
    long double ans = -1;
    cin >> n >> u;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n-2)  {
        int k = search(i+2, n-1, a[i]);
        if(k != -1) ans = max(ans, ((long double)a[k] - a[i+1]) / ((long double)a[k] - a[i]));
    }
    if(ans < 0) cout << -1;
    else cout << setprecision(13) << fixed << ans;
}