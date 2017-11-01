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
#define maxn 1505
int n, q, m, c, dp[26][maxn];
string s;
void solve (char x) {
	FOR(used,1,n+1) {
		int l = 0, r = 0, cur = 0;
		int &ans = dp[x-'a'][used];
		while(l < n) {
			if(r == n) { ans = max(r-l, ans); if(s[l] != x) cur--; l++;}
			else if(s[r] == x) {r++;}
			else if(cur >= used) {
				ans = max(ans, r-l);
				if(s[l] != x) cur--;
				l++;
			} else {
				r++;
				cur++;
			}
		}
	}
}
int main() {
	SYNC;
	cin >> n >> s;
	FOR0(i, 26) {
		solve('a' + i);
	}
	cin >> q; char cq;
	while(q--) {
		cin >> m >> cq;
		cout << dp[cq-'a'][m] << endl;
	}
}