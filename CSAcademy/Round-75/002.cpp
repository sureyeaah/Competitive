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
int h, w; char grid[505][505];
int di[4] = {1, 0, -1, 0}, dj[4] = {0, -1, 0, 1};
int dir[500];
int ans = 0;
int vis[505][505];
void dfs(int i, int j) {
    int ni = i + di[dir[grid[i][j]]];
    int nj = j + dj[dir[grid[i][j]]];
    // cerr << i << j << ni << nj << endl;
    if(ni < 0 || nj < 0 || ni >= h || nj >= w) {
        vis[i][j] = 3;
    } else {
        vis[i][j] = 1;
        if(!vis[ni][nj]) dfs(ni, nj);
        if(vis[ni][nj] == 3) vis[i][j] = 3;
    }
    // if(vis[i][j] == 3) { ans++;}
}
int main() {
    SYNC
    dir['D'] = 0; dir['L'] = 1; dir['U'] = 2; dir['R'] = 3;
    cin >> h >> w;
    FOR0(i, h) FOR0(j, w) cin >> grid[i][j];
    FOR0(i, h) FOR0(j, w) if(!vis[i][j]) dfs(i, j);
    FOR0(i, h) FOR0(j, w) if(vis[i][j] == 3) ans++;
    cout << ans;
}