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

int main() {
	int t, k, n;
	char s[1000 + 10];
	bitset<1000 + 10> bs;
	scanf("%d%*c", &t);
	FOR(caseNum,1,t+1) {
		printf("Case #%d: ", caseNum);
		scanf("%[^ ]%d%*c", s, &k);
		bs.reset();
		n = strlen(s);
		FOR0(i, n) bs[i] = (s[i] == '+') ? 0 : 1;
		int ans = 0;
		FOR0(i, n-k+1) if(bs[i] && ++ans) FOR(j,i,i+k) bs.flip(j);
		if(bs.any()) printf("IMPOSSIBLE\n");
		else printf("%d\n",ans);
	}
}