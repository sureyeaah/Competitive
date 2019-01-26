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
const int N = 2e5+5;
int a[N][2], t, n, x[N][25];
int upd(int j, int pos, int r=1) {
    int cost = 0;
    FOR0(i, n) {
        if(x[i][j]) a[i][r] = a[i][0] == inf? inf: (a[i][0]<pos?a[i][0]:a[i][0]+1); 
        else a[i][r] = min(a[i][0], pos);
        cost += a[i][r]==inf?t-j: a[i][r]+1;
    }
    return cost;
}
int main() {
    SYNC
    ifstream cin("tests.in");
    int p;
    cin >> p;
    while(p--) {
        cin >> t >> n;
        FOR0(i, n) a[i][0] = inf;
        FOR0(i, n) {
            FOR0(j, t) {
                char c;
                cin >> c;
                x[i][j]=c-'0';
            }
        }
        V<int> sol;
        int ans=inf;
        FORD(j, 0, t) {
            P<int, int> best({inf, -1});
            FOR0(pos, t-j) {
                P<int, int> val = make_pair(upd(j, pos, 1), pos);
                best = min(val, best);
            }
            ans=upd(j, best.ss, 0);
            cerr << ans << endl;
            sol.insert(sol.begin()+best.ss, j);
        }
        cout << ans << endl;
        for(int x: sol) cout << x+1 << " " ;
        cout << endl;
    }
}