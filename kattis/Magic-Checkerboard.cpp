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
#define inf ((int)1e9)
#define INF ((ll)1e18)
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
#define N 2005
int n, m, a[N][N], b[N][N], p[2];
int par[2] = {-1, -1};
ll calc() {
    ll ans = 0;
    FOR0(i, 2) {
        if(par[i] != -1 && p[i] != par[i]) return INF;
    }
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            a[i][j] = b[i][j];
        }
    }
    FOR(i, 1, n+1) {
        FOR(j,1,m+1) {
            if(!a[i][j]) {
                a[i][j] = max(a[i-1][j], a[i][j-1]) + 1;
                if(a[i][j] < -inf) a[i][j] = 1;
                if(((a[i][j] + j) & 1) != p[(i+j)&1]) a[i][j]++;
            }
            if((a[i][j+1] > 0 && a[i][j] >= a[i][j+1]) || (a[i+1][j] > 0 && a[i][j] >= a[i+1][j])) {
                return INF;
            }
            ans += a[i][j];
        }
    }
    // DEBUG(p[0]);
    // DEBUG(p[1]);
    // FOR(i,1,n+1) {
    //     FOR(j,1,m+1) {
    //         cout << a[i][j] << " \n"[j==m];
    //     }
    // }
    return ans;
}
int main() {
    SYNC
    memset(a, -63, sizeof a);
    memset(b, -63, sizeof b);
    cin >> n >> m;
    if(n == 1 || m == 1) {
        int prev = 0, x; int ans = 0;
        FOR(i, 1, n+1) {
            FOR(j, 1, m+1) {
                cin >> x;
                if(!x) x = prev + 1;
                ans += x;
                if(x <= prev) {cout << -1 << newl; return 0;}
                prev=  x;
            }
        }
        cout << ans;
        return 0;    
    }
    FOR(i, 1, n+1) {
        FOR(j, 1, m+1) {
            cin >> b[i][j];
            if(b[i][j]) {
                int x = (i + j) & 1;
                if(par[x] == -1) par[x] = (b[i][j] + j) &1;
                else if (par[x] != ((b[i][j] + j) & 1)) {
                    cout << -1; return 0;
                }
            }
        }
    }
    ll ans = INF;
    for(p[0] = 0; p[0] < 2; p[0]++) {
        for(p[1] = 0; p[1] < 2; p[1]++) {
            ans = min(ans, calc());
        }
    }
    cout << (ans < INF ? ans : -1) << endl;
}