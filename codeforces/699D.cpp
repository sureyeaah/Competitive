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
const int N = 2e5 + 5;
int n, a[N];
vector<int> vis(N), vec;
void dfs(int u) {
    vis[u] = 1;
    if (!vis[a[u]]) dfs(a[u]);
    else if (vis[a[u]] == 1) vec.push_back(u);
    vis[u] = 2;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> a[i+1];
    int root = 0, ans = 0;
    FOR(i, 1, n+1) {
        if(a[i] == i) root = i;
    }
    FOR(i, 1, n + 1) if(!vis[i]) dfs(i);
    if(!root && vec.size()) root = vec[0];
    if(root) {
        for(int i : vec) {
            if(a[i] == root) continue;
            ans++, a[i] = root;
        }
    }
    cout << ans << endl;
    FOR(i, 1, n + 1) cout << a[i] << " ";
}