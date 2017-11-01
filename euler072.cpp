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
#define N 1000005
int t, n, tot[N];
ll dp[N];
bitset<N> bs;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    FOR0(i, N) tot[i] = i;
    FOR(i,2,N) {
        if(!bs[i]) continue;
        for(int j = i; j < N; j+=i) {
            bs[j] = 0;
            tot[j] = (tot[j]/i) * (i-1);
        }
    }
}
int main() {
    SYNC
    sieve();
    cin >> t;
    dp[1] = 0;
    FOR(i,2,N) dp[i] = dp[i-1] + tot[i];
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
}