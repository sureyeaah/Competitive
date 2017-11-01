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
#define maxn 200005
int n, dp[maxn] = {};
bitset<500> bs;
int best = 0;
vvi factors(maxn);
int check(int i) {
    bs.reset();
    int ret = -1;
    for(int k : factors[2*i]) {
        int a = (i*2)/k + 1 - k;
        if(a & 1) continue; else a/= 2;
        if(a >= 1) {
            int g = dp[a + k - 1]^dp[a-1];
            if (g == 0 && ret == -1) ret = k;
            bs[g] = 1;
        }
    }
    int val = 0;
    while(bs[val]) val++;
    dp[i] = dp[i-1] ^ val;
    return ret;
}
int main() {
    SYNC
    cin >> n;
    int ans = -1;
    for(int i = 2; i <= 2*n; i++) {
        for (int j = i; j <=2*n; j+=i) factors[j].pb(i);
    }
    FOR(i,2,n+1) ans = check(i);
    cout << ans;
}