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
#define N 100005
int main() {
    SYNC
    int k, dp[N][10], best[N] = {}, cnt[10] = {6,2,5,5,4,5,6,3,7,6};
    cin >> k;
    if(k == 6) {
        cout << 0; return 0;
    }
    memset(dp, 63, sizeof dp);
    dp[0][0] = 0;
    FOR(i,1,k+1) {
        FOR(digit,0,10) {
           if(i-cnt[digit] >= 0) dp[i][digit] = dp[i-cnt[digit]][best[i-cnt[digit]]] + 1; 
           if(dp[i][digit] < dp[i][best[i]]) best[i] = digit;
        }
    }
    best[k] = 1;
    FOR(i,1,10) if(dp[k][i] < dp[k][best[k]]) best[k] = i;
    if(dp[k][best[k]] < INF) {
        while(k) {
            cout << best[k];
            k -= cnt[best[k]];
        }
    } else cout << -1;
}