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
#define maxn 1000005
int t, m, n, k, dp[maxn], tot[maxn];
bitset<maxn> bs;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	FOR(i,1,maxn) tot[i] = i;
	FOR(i,2,maxn) {
		if(!bs[i]) continue;
		tot[i] = i-1;
		for(int j = i*2; j < maxn; j+=i) {bs[j] = 0; tot[j] = (tot[j]/i) * (i-1);}
	}
}
vi ans[25];
int main() {
	SYNC;
	sieve();
	memset(dp,0,sizeof dp);
	ans[0].pb(1);
	FOR(i,2,maxn) {
		dp[i] = dp[tot[i]] + 1;
		if(dp[i] <= 20) ans[dp[i]].pb(i);
	}
	cin >> t;
	while(t--) {
		cin >> m >> n >> k;
		cout << upper_bound(ans[k].begin(), ans[k].end(), n)-upper_bound(ans[k].begin(), ans[k].end(),m-1) << '\n';
	}
}