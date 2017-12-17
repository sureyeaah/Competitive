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
const int A = 505;
int a, d, dp[A][1 << 5][1 << 5] = {}, finish;
string s;
void fix(int &p, int &n, int u, int v) {
    if(abs(u - v) > d) return;
    if(u > v) p |= 1 << (u - v - 1);
    else n |= 1 << (v - u - 1);
}
int go(int cur, int pre, int nxt) {
    if(dp[cur][pre][nxt] != -1) return dp[cur][pre][nxt];
    int& ans = dp[cur][pre][nxt];
    if(cur == a-1) return ans = (pre == finish);
    ans = 0;
    FOR(x, 1, d + 1) {
        if((nxt & (1 << (x-1)))==0 && (s[cur] == '?' || s[cur] == '0' + x) && cur+x < a) {
            int p = 0, n = 0;
            fix(p, n, cur + x, cur);
            FOR(i, 1, d + 1) if(nxt & (1 << (i-1))) fix(p, n, cur + x, cur + i);
            FOR(i, 1, d + 1) if(pre & (1 << (i-1))) fix(p, n, cur + x, cur - i);
            ans = (ans + go(cur + x, p ,n)) % mod;
        }
    }
    FOR(x, 1, d + 1) {
        if((pre & (1 << (x-1)))==0 && (s[cur] == '?' || s[cur] == '0' + x) && cur-x >= 0) {
            int p = 0, n = 0;
            fix(p, n, cur - x, cur);
            FOR(i, 1, d + 1) if(nxt & (1 << (i-1))) fix(p, n, cur - x, cur + i);
            FOR(i, 1, d + 1) if(pre & (1 << (i-1))) fix(p, n, cur - x, cur - i);
            ans = (ans + go(cur - x, p ,n)) % mod;
        }
    }
    return ans;
}
int main() {
    SYNC
    cin >> s >> d; a = s.length();
    memset(dp, -1, sizeof dp);
    int finish = (1 << min(d, a-1)) - 1;
    cout << go(0, 0, 0) << newl;
    DEBUG(dp[5][7][0]);
}