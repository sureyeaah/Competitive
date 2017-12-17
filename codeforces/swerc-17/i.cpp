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
#define INF ((ll)9e18)
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
const int N = 1005, M = 5005, L = 12;
int n, m, ans = 0, dp[N][L+1][L+1]={}, cnt[N][M] = {}; char x, g[N][M];
int leftclosest[N][M]={}, rightclosest[N][M]={};
vvi ladder(N);
inline int jars(int f, int st, int nd) {
    if(st > nd) return 0;
    return cnt[f][nd] - cnt[f][st-1];
}
int overlap(int f, int p1, int p2, int p3, int p4) {
    if(p1 > p2) swap(p1, p2);
    if(p3 > p4) swap(p3, p4);
    if(p1 <= p3  && p3 <= p2 && jars(f, p3, min(p2, p4))) return 1;
    if(p1 <= p4 && p4 <= p2 && jars(f, max(p1, p3), p4)) return 1;
    if(p3 <= p1 && p2 <= p4 && jars(f, p1, p2)) return 1;
    return 0;
}
int main() {
    SYNC
    cin >> n >> m;
    FOR(i, 1, n + 1) {
        FOR(j, 1, m + 1) {
            cin >> g[i][j];
            cnt[i][j] = cnt[i][j-1] + (g[i][j]=='-'?0:g[i][j]-'0');
        }
        FOR(j, 1, m + 1) {
            cin >> x;
            if(x=='|') ladder[i+1].pb(j);
        }
    }
    FOR(i,1,n+1) {
        FOR(j, 2, m + 1) {
            leftclosest[i][j] = (g[i][j-1]=='-'? leftclosest[i][j-1] :g[i][j-1]-'0');
        }
        FORD(j, 1, m) {
            rightclosest[i][j] = (g[i][j+1]=='-'? rightclosest[i][j+1] :g[i][j+1]-'0');
        }
    }
    FORD(i,2,n+1) {
        FOR0(l, SZ(ladder[i])) {
            FOR0(r, SZ(ladder[i])) {
                int& cur = dp[i][l][r];
                int d = ladder[i][l], u = ladder[i][r];
                if(d == u) {
                    cur = jars(i, d, d);
                    if(!cur) cur = leftclosest[i][d] + rightclosest[i][u];
                }
                else {
                    if(d > u) swap(d, u);
                    cur += leftclosest[i][d+1];
                    cur += jars(i, d+1, u - 1);
                    cur += rightclosest[i][u-1];
                }

                FOR0(nl, SZ(ladder[i+1])) {
                    FOR0(nr, SZ(ladder[i+1])) {
                        int nd = ladder[i+1][nl], nu = ladder[i+1][nr], val = dp[i+1][nl][nr];
                        if(nd==nu && jars(i, nd, nu)) continue;
                        if(overlap(i, d, nd, u, nu)) continue;
                        val += nd < d ? jars(i, nd, d): jars(i, d, nd);
                        val += nu < u ? jars(i, nu, u): jars(i, u, nu);
                        if(max(nd, d) < min(nu, u)) {
                            int pt = min(d,nd), b = 0;
                            if(!jars(i,pt,pt)) val += leftclosest[i][pt];
                            pt = max(u, nu);
                            if(!jars(i,pt,pt)) val += rightclosest[i][pt];
                            pt = max(d, nd); int ppt = min(u, nu);
                            if(!jars(i, pt, pt)) b += rightclosest[i][pt];
                            if(!jars(i, ppt, ppt)) b += leftclosest[i][ppt];
                            val += min(b, jars(i, pt + 1, ppt - 1));
                        } else {
                            int pt = min(d, min(nd, nu));
                            if(!jars(i, pt, pt)) val += leftclosest[i][pt];
                            pt = max(u, max(nd, nu));
                            if(!jars(i, pt, pt)) val += rightclosest[i][pt];
                        }
                        cur = max(cur, val);
                    }
                }
                if(i==2)ans = max(ans, cur);
            }
        }
    }
    cout << ans;
    cerr << dp[3][0][0];
}