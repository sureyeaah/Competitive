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
#define N 505
#define val(r, c) (dp[r][c] + dp[r+k][c+k] - dp[r][c+k]-dp[r+k][c])
#define valid(r,c) (r >= 0 && c >= 0 && r < n && c < n)
int n, k, grid[N][N], vis[N][N] = {}, comp[N][N] = {}; char x;
int comps = 0, sz[N*N] = {}, cnt[N*N] = {}, ans = 0;
#define INC(r, c, val) cnt[comp[r][c]]+=val; if(cnt[comp[r][c]] == (val == 1)) cursz += val*sz[comp[r][c]];
int main() {
    int di[4] = {0,1,0,-1}, dj[4] = {1,0,-1,0};
    SYNC
    cin >> n >> k;
    FOR0(i, n) FOR0(j, n) {
        cin >> x;
        grid[i][j] = x == '.';
    }
    FOR0(i, n) {
        FOR0(j, n) {
            if(!vis[i][j] && grid[i][j]) {
                queue<ii> q({mp(i, j)});
                comps++;
                while(!q.empty()) {
                    int r= q.front().ff, c = q.front().ss; q.pop();
                    if(vis[r][c]) continue;
                    comp[r][c] = comps;
                    sz[comps]++;
                    vis[r][c] = 1;
                    FOR0(k, 4) {
                        int nr = r + di[k], nc = c + dj[k];
                        if(valid(nr, nc) && grid[nr][nc] && !vis[nr][nc]) {
                            q.push(mp(nr, nc));
                        }
                    }
                }
            }
        }
    }
    int dp[N][N] = {};
    FORD(i,0,n) {
        FORD(j,0,n) {
            dp[i][j] = dp[i][j+1] + dp[i+1][j] - dp[i+1][j+1] + !grid[i][j];
        }
    }
    int cursz = 0;
    FOR0(i, k+1) {
        FOR0(j, k+1) {
            if(i == k && j == k) continue;
            INC(i, j, 1);
        }
    }
    ans = max(cursz + val(0,0), ans);
    int r = 0, c = 0, dir = 1;
    while(1) {
        int nc = c + dir;
        if(nc > n - k || nc < 0) {
            if(r == n - k) break;
            if(r > 0) {
                FOR(i,c,c+k) {
                    INC(r-1, i, -1);
                }
            }
            if(r+k+1 < n) {
                FOR(i,c,c+k) {
                    INC(r+k+1, i, 1);
                }
            }
            if(valid(r, c-1))  {INC(r, c-1, -1);}
            if(valid(r, c+k)) {INC(r, c+k, -1);}
            if(valid(r+k, c-1))  {INC(r+k, c-1, 1);}
            if(valid(r+k, c+k)) {INC(r+k, c+k, 1);}
            dir *= -1; r++;
            ans = max(cursz + val(r,c), ans);
            continue;
        }
        int cc = (dir == 1) ? c - 1: c + k;
        if(valid(r, cc)) {
            FOR(i,r,r+k) {
                INC(i, cc, -1);
            }
        }
        cc = (dir == 1) ? c+k+1: c-2;
        if(valid(r, cc)) {
            FOR(i,r,r+k) {
                INC(i, cc, 1);
            }
        }
        if(dir == -1) c--;
        if(valid(r-1, c))  {INC(r-1, c, -dir);}
        if(valid(r+k, c)) {INC(r+k, c, -dir);}
        if(valid(r-1, c+k))  {INC(r-1, c+k, dir);}
        if(valid(r+k, c+k)) {INC(r+k, c+k, dir);}
        if(dir == -1) c++;
        c = nc;
        ans = max(cursz + val(r, c), ans);
    }
    cout << ans;
}