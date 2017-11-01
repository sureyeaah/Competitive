#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)2e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1e5 + 5;
int n, sq, a[N], b[N], block[N], arr[N], value[N], sorted[N], ind[N];
vvi g(N);
ll ans = 0;
int query(int l, int r, int val) {
    if(l > r) return 0;
    int ans = 0;
    if(block[l] != block[r]) {
        for(; l < sq; l++)
            if(value[l] < val) ans++;
    }
    while(block[l] != block[r]) {
        ans += lower_bound(arr + l, arr + l + sq,val) - (arr + l);
        l = (block[l] + 1) * sq;
    }
    for(int i = l; i <= r; i++)
        if(value[i] < val) ans++;
    return ans;
}
void update(int x, int val) {
    int i, j;
    for(i = block[x]*sq; i < n && i < (block[x] + 1) * sq; i++)
        if(arr[i] == value[x]) break;
    arr[i] = value[x] = val;
    j = i;
    for(; j > block[x]*sq && arr[j] < arr[j-1]; j--)
        swap(arr[j], arr[j-1]);
    for(; j+1 < min(n, (1+block[x])*sq) && arr[j] > arr[j+1]; j++)
        swap(arr[j], arr[j+1]);

}
void dfs(int u, int prev) {
    ans += query(0, lower_bound(sorted, sorted + n, a[u]) - sorted - 1, b[u]);
    update(ind[u], b[u]);
    for(int v : g[u]) {
        if(v == prev) continue;
        dfs(v, u);
    }
    update(ind[u], inf);
}
int main() {
    SYNC
    cin >> n;
    sq = (int)pow(n, 0.5);
    FOR0(i, n-1) {
        int u, v; 
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    FOR0(i, n) {
        cin >> a[i+1];
    }
    FOR0(i, n) {
        cin >> b[i+1];
    }
    vii vec;
    FOR0(i, n)
        vec.pb(mp(a[i+1], i+1));
    sort(vec.begin(), vec.end());
    FOR0(i, n) {
        ind[vec[i].ss] = i;
        sorted[i] = vec[i].ff;
    }
    int cnt = 0;
    FOR0(i, n) value[i] = inf;
    for(int i = 0; i < n; i+= sq) {
        for(int j = i; j < n && j < i + sq; j++) {
            block[j] = cnt;
            arr[j] = inf;
        }
        cnt++;
    }
    dfs(1, 0);
    cout << ans;
}