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
int t, c, a[105], b[105]; char grid[105][105];
int r;
void connect(int c, int cc) {
    char x = c < cc ? '\\': '/';
    FOR0(i, abs(c-cc)) {
        grid[i][c] = x;
        c += c < cc ? 1: -1;
    }
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> c;
        memset(b, -1, sizeof b);
        FOR0(i, c) cin >> a[i];
        int ans = !(a[0] == 0 || a[c-1] == 0), rem = 0, l=-1;
        FOR0(i, c) {
            if(b[i] == -1) rem++;
            while(rem && a[i]) {
                b[++l] = i;
                rem--;
                a[i]--;
            }
            while(a[i]) {
                b[++l] = i;
                a[i]--;
            }
        }
        if(ans) {
            r = 0;
            FOR0(i, c) r = max(r, abs(b[i] - i) + 1); 
            FOR0(i, r) FOR0(j, c) grid[i][j] = '.';
            FOR0(i, c) connect(i ,b[i]);
            cout << printCase() << r << endl;
            FOR0(i, r) {
                FOR0(j, c) cout << grid [i][j];
                cout << endl;
            }
        }
        else {
            cout << printCase() << "IMPOSSIBLE" << endl;
        }
    }
}