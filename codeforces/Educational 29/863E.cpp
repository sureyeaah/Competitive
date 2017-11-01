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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 200005;
const int MAXN = 3*N;
int main() {
    SYNC
    int n, l[N], r[N], cnt = 0, dp[MAXN] = {};
    map<int ,int> m;
    cin >> n;
    FOR0(i, n) cin >> l[i] >> r[i];
    FOR0(i, n) {
        m[l[i]] = 1;
        m[r[i]] = 1;
        m[r[i]+1] = 1;
    }
    for(auto& x : m) x.ss = ++cnt;
    FOR0(i, n) l[i] = m[l[i]];
    FOR0(i, n) r[i] = m[r[i]];
    FOR0(i, n) {
        dp[l[i]]++;
        dp[r[i] + 1]--;
    }
    FOR(i, 1, MAXN) dp[i] += dp[i-1];
    FOR(i,1,MAXN) dp[i] = dp[i-1] + (dp[i] == 1);
    int ans = -1;
    FOR0(i, n) if(dp[r[i]] - dp[l[i]-1] == 0) ans = i+1;
    cout << ans;
}