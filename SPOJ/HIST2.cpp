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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 15
int n, dp[1 << maxn][maxn+2], h[maxn + 2];
ll cnt[1 << maxn][maxn+2];

int go(int mask, int last) {
    if(dp[mask][last]) return dp[mask][last];
    int nxt = mask | (1 << last);
    FOR0(i, n) {
        if(nxt & (1 << i)) continue;
        go(nxt, i);
        int newVal = dp[nxt][i] + h[last] - h[i] + abs(h[last] - h[i]);
        if(newVal > dp[mask][last]) {
            cnt[mask][last] = cnt[nxt][i];
            dp[mask][last] = newVal;
        } else if(newVal == dp[mask][last]) {
            cnt[mask][last] += cnt[nxt][i];
        }
    }
    return dp[mask][last];
}
int main() {
    SYNC;
    while(cin >> n && n) {
        FOR0(i, n) cin >> h[i];
        memset(dp,0,sizeof dp);
        memset(cnt,0,sizeof cnt);
        FOR0(i, n) {
            int x = ((1 << n) - 1) & ~ (1 << i);
            cnt[x][i] = 1;
            dp[x][i] = 2*h[i];
        }
        FOR0(i, n) go(0, i);
        int best = *max_element(dp[0], dp[0] + n);
        ll tot = 0;
        FOR0(i,n) if(dp[0][i] == best) tot += cnt[0][i];
        cout << best + 2*n << " " << tot << '\n';
    }
}