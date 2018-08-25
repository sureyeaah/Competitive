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
int n, a[N], b[N], c[2*N];
ll solve(int x) {
    memset(c, 0, sizeof c);
    FOR0(i, n) b[i+1] = a[i] < x ? -1: 1;
    b[0] = n;
    FOR0(i, n) b[i+1] += b[i];
    ll ans = 0, cur = 0; c[n] = 1;
    FOR(i, 1, n + 1) {
        if(b[i] > b[i-1]) {
            cur += c[b[i]] + 1;
        }
        else {
            cur -= c[b[i-1]]-1;
        }
        c[b[i]]++;
        ans += cur;
    }
    return (n*1LL*(n+1))/2 - ans;
}
int main() {
    SYNC
    cin >> n;
    map<int, int> m; int cnt = 0;
    FOR0(i, n) {
        cin >> a[i];
        if(!m[a[i]]) m[a[i]] = 1;
    }
    for(auto& x : m) x.second = ++cnt;
    FOR0(i, n) a[i] = m[a[i]];
    int l = 1, r = cnt, ans = -1;
    ll target = (n * 1LL * (n + 1)) / 2;
    target = (target/2 + 1);
    while(l <= r) {
        int mid = (l + r) >> 1;
        ll y = solve(mid);
        cerr << mid << " " << y << endl;
        if(y < target) {
            ans = mid; l = mid + 1;
        } else r = mid - 1;
    }
    for(auto x : m) {if(x.second == ans) {ans = x.first; break;}}
    cout << ans;
}