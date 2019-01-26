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
const int N = 21;
int n, m, c[N][N];
unordered_set<int> x[N][N];
int main() {
    SYNC
    cin >> n >> m;
    FOR0(i, n) FOR0(j, m) cin >> c[i][j];
    x[0][0].insert(c[0][0]);
    FOR0(i, n) {
        FOR0(j, m) {
            int pi = i - 1, pj = j - 1;
            if(pi >= 0) {
                for(int a : x[pi][j]) x[i][j].insert(a ^ c[i][j]);
            }
            if(pj >= 0) {
                for(int a : x[i][pj]) x[i][j].insert(a ^ c[i][j]);
            }
        }
    }
    cout << x[n-1][m-1].size();
}