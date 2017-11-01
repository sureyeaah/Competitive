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
	int t, m, w, h, height[20000 + 10];
	vi wh[10000 + 10];
	scanf("%d",&t);
	while(t--) {
		memset(height,0,sizeof height);
		scanf("%d", &m);
		FOR0(i, 10001) wh[i].clear();
		FOR0(i, m) {
			scanf("%d%d", &w, &h);
			wh[w].pb(h);
		}
		int ans = 0;
		FOR0(i, 10001) {
			sort(wh[i].begin(), wh[i].end(), greater<int> ());
			int j = 0;
			for(auto curr: wh[i]) {
				j = upper_bound(height+j, height+ans, -curr) - height;
				if(j == ans) ans++;
				height[j++] = -curr; 
			}
		}
		printf("%d\n", ans);
	}
}