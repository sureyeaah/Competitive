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
int n, a[300000 + 5], u, v;
vvi graph(300000 + 5);
vi v1, v2;
//bitset<300000+5> online;
int main() {
	SYNC;
	cin >> n;
	FOR0(i, n) cin >> a[i+1];
	//FOR(i,1,n+1) online[i] = 1;
	FOR0(i, n-1) {
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int maxVal = *max_element(a+1, a+n+1);
	int ans = maxVal, maxNum = 0;
	vi cnt(n+1,0);
	FOR(i,1,n+1) {
		if(a[i]<maxVal) continue;
		maxNum++;
		repi(j, graph[i]) {
			cnt[*j]++;
		}
	}

	if(maxNum>1) {
		FOR(i,1,n+1) {
			if(cnt[i] == maxNum || (cnt[i] == maxNum-1 && a[i]==maxVal)) {
				ans--;
				break;
			}
		}
		ans += 2;
		cout << ans << endl;
		return 0;
	}
	cnt.assign(n+1, 0);
	int smax = 0;
	FOR(i,1,n+1) {
		if(a[i]!=maxVal-1) continue;
		smax++;
		repi(j, graph[i]) {
			cnt[*j]++;
		}
	}
	if(smax>=1) {
		FOR(i,1,n+1) {
			if(cnt[i] == smax && a[i] == maxVal) {
				ans--;
				break;
			}
		}
		ans += 1;
		cout << ans << endl;
		return 0;
	}
	cout << ans << endl;
}