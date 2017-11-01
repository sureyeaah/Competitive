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
#define mod (7+(int)1e9)
int main() {
	SYNC;
	int n, k, a[500005], longest[500005] = {}, cnt[500005] = {}, dp[500005] = {}, sum[500005] = {};
	cin >> n >> k;
	k = min(k, n);
	FOR0(i, n) cin >> a[i];
	int l = 0, r = 0;
	set<int> s;
	FOR0(i, k+1) s.insert(i);
	while(l < n) {
		if(r == n) {longest[l] = r-l; l++; continue;} 
		if(a[r] <= k) {
			if(s.size() == 1 && a[r] == *s.begin()) {
				longest[l] = r-l;
				if(a[l] <= k) {
					cnt[a[l]]--; if(!cnt[a[l]]) s.insert(a[l]);
				}
				l++;
			} else {
				if(!cnt[a[r]]) s.erase(a[r]);
				cnt[a[r]]++;
				r++;
			}
		} else r++;
	}
	sum[n] = 1;
	dp[n] = 1;
	FORD(i,0,n) {
		dp[i] = ((sum[i+1] - sum[i+longest[i]+1]) % mod + mod) % mod;
		sum[i] = (dp[i] + sum[i+1]) % mod;
	}
	cout << dp[0] << endl;
}