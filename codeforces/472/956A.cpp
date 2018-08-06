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
const int N = 55; int n, m;
int r[N], c[N], g[N][N]; char x;
int check(int r1, int r2) {
    int f = 0;
    FOR0(j, m) {
        if(g[r1][j] == 1 && g[r2][j] == 1) f = 1;
    }
    FOR0(j, m) {
        if(g[r1][j] != g[r2][j] && f) return 0;
    }
    return 1;
}
int main() {
    SYNC
    cin >> n >> m;
    V<P<int,int>> v;
    FOR0(i, n) {
        FOR0(j, m) {
            cin >> x;
            g[i][j] = x=='#';
            // if(x=='#') v.pb(mp(i, j));
        }
    }
    int ans = 1, cur = 1, st=0;
    FOR0(i, n) {
        FOR0(j, i) {
            if(!check(i, j)) ans = 0;
        }
    }
    cout << (ans ? "YES" : "NO");
}