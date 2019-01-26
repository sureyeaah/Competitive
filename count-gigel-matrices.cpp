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
#define INF ((int)1e9)
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
#define valid(r,c) (r <= n && c <= m)
int n, m, dp[N][N] = {}, arr[N][N];
ll ans = 0;
class fenwick {
public:
    int seg[4*N] = {};
    int query(int p, int l, int r) {
    //     int ans = 0;
    //     for(; i; i-=i&-i)
    //         ans += ft[i];
    //     return ans;
    // }
    // void upd(int i, int val) {
    //     for(; i < N; i+=i&-i)
    //         ft[i] += val;
    // }
};
ll solve(int r, int c) {
    int reach[N] = {};
    fenwick ft;
    while(valid(r,c)) {
        int rr = r, cc = c;
        while(valid(rr, cc) && arr[rr][cc]) {
            rr++;
            cc++;
        }
        
    }
}
int main() {
    SYNC
    char c;    
    cin >> n >> m;
    FOR0(i, n) {
        FOR0(j, m) {
            cin >> c;
            arr[i+1][j+1] = c == '1';
            dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + (c == '1');
        }
    }
    // ans = dp[n][m];
    FOR0(i, n) ans += solve(i+1,1);
    FOR(i, 1, m) ans += solve(1,i+1);
    cout << ans;
}