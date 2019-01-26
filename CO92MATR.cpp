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
int t, n, m, a[105][105];
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> m;
        FOR0(i, n) FOR0(j, m) cin >> a[i][j];
        int ans = 1;
        if(a[0][0] == -1) a[0][0] = 1;
        FOR0(i, n) {
            FOR0(j, m) {
                if(a[i][j] == -1) {
                    if(i) a[i][j] = max(a[i][j], a[i-1][j]);
                    if(j) a[i][j] = max(a[i][j-1], a[i][j]);
                } else {
                    if(i && a[i][j] < a[i-1][j]) ans=0;
                    if(j && a[i][j] < a[i][j-1]) ans=0;
                }
            }
        }
        if(ans) {
            FOR0(i, n) {
                FOR0(j, m) {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        } else cout << -1 << endl;
    }
}