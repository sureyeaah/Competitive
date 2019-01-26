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
int t, n, a[10][10], b[10][10];
unordered_map<int, int> rcnt[5], ccnt[5];

int backtrack(int x) {
    int ans = inf;
    if(x == n * n) {
        ans = 0;
        FOR0(i, n) {
            FOR0(j, n) {
                if(a[i][j] != b[i][j]) ans++;
            }
        }
        return ans;
    }
    int r = x/n, c = x%n;
    for(b[r][c] = -n; b[r][c] <= n; b[r][c]++) {
        if(!b[r][c] || rcnt[r][b[r][c]] || ccnt[c][b[r][c]]) continue;
        rcnt[r][b[r][c]]++; ccnt[c][b[r][c]]++;
        ans = min(ans, backtrack(x+1));
        rcnt[r][b[r][c]]--; ccnt[c][b[r][c]]--;
    }
    return ans;
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> n;
        FOR0(i, n) {
            FOR0(j, n) {
                cin >> a[i][j];
                rcnt[i].clear(); ccnt[j].clear();
            }
        }
        cout << printCase() << backtrack(0) << endl;
    }
}