#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int a[10];
ll choose[30][30];
ll dp[11][21];

ll ways(int k, int leadingZeroes) {
	memset(dp, 0, sizeof(dp));
	dp[10][0] = 1;
	FORD(digit,0,10) {
		if(!digit && leadingZeroes) {
			FOR(taken,1,k) {
				if(taken == a[0]) continue;
				FOR(len,1,k-taken+1) {
					dp[0][k] += dp[1][len]*choose[len+taken-1][taken];
				}
			}
			if(a[0]) FOR(taken,1,k+1) dp[0][k] += dp[1][taken];
			continue;
		}
		FOR0(taken,k+1) {
			if(a[digit] == taken) continue;
			FOR0(len,k-taken+1) {
				dp[digit][len+taken] += dp[digit+1][len]*choose[len+taken][taken];
			}
		}
	}
	return dp[0][k];
}
ll query(string num, int leadingZeroes) {
	if(!(num.length()))
		return 0;
	ll ans = 0;
	FOR0(i, num[0]-'0') {
		if(i || !leadingZeroes) a[i]--;
		ans += (num.length() == 1 && !a[i]) ? 0: ways(num.length()-1, leadingZeroes&(!i));
		if(i || !leadingZeroes)a[i]++;
	}
	a[num[0]-'0']--;
	ans += query(num.substr(1), 0);
	a[num[0]-'0']++;
	return ans;
}

int main() {
	memset(choose, 0, sizeof(choose));
	FOR0(i, 30) choose[i][0] = 1;
	FOR(i, 1, 30) FOR(j, 1, i+1) choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
	int t;
	cin >> t;
	while(t--) {
		ll l, r;
		cin >> l >> r;
		FOR0(i, 10) cin >> a[i];
		string s1 = to_string(l), s2 = to_string(r);
		ll ans = 1;
		FOR0(i, 10) {
			if(count(s2.begin(), s2.end(), '0'+i) == a[i]) {
				ans--;
				break;
			}
		}
		ans += query(s2, 1)-query(s1, 1);
		cout << ans << endl;
	}
}