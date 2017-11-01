#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
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
string s; int n, k, cnt[2][26];
int main() {
	SYNC;
	memset(cnt, 0, sizeof cnt);
	cin >> k >> s;
	n = s.length();
	int start = 0, ans = 0;
	FOR0(i, n) {
		cnt[i&1][s[i] - 'a']++;
		while(1) {
			int maxSum = *max_element(cnt[0], cnt[0]+26) + *max_element(cnt[1], cnt[1] + 26);
			if(maxSum+k >= i-start+1) break;
			cnt[start&1][s[start]-'a']--;
			start++;
		}
		ans = max(ans, i-start+1);
	}
	cout << ans;
}