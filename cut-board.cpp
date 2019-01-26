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
const int N = 105;
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int dp[N][N][4];
int bl(int r, int c) {
    return r==0||c==0||r>n||c>m||(r==1 && c<=x) || (r==n&&c<=m-y);
}
int main() {
    SYNC
    cin >> n >> m >> x >> y;
    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            int c=0;
            FOR0(d, 4) {
                int od = (d + 2) % 4, ni = i+dx[d], nj = j+dy[d];
                if(bl(ni,nj)) continue;
                if(ni>i||nj>j||dp[ni][nj][od]accumulate(dp[ni][nj], dp[ni][nj]+4,0)==)
            }
            FOR0(d, 4) {
                int od = (d + 2) % 4, ni = i+dx[d], nj = j+dy[d];
                if(bl(ni,nj)) continue;
                if(ni>i||nj>j||dp[ni][nj][od]) dp[i][j][d]=1;
            }
        }
    }
}