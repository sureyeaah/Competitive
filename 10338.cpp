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

int main() {
	ll factorial[21];
	factorial[0] = 1;
	FOR(i,1,21) factorial[i] = factorial[i-1]*((ll)i);
	int n; cin >> n; string s; int cnt[26];
	FOR(caseNum,1,n+1) {
		memset(cnt,0,sizeof cnt);
		cin >> s;
		FOR0(i, s.length()) cnt[s[i]-'A']++;
		ll ans = factorial[s.length()];
		FOR0(i, 26) ans = ans/factorial[cnt[i]];
		printf("Data set %d: %lld\n", caseNum, ans);
	}
}