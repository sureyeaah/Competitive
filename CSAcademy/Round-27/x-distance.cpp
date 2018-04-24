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
int n, m, x, a, b, w, dist[100005], num[100005] = {}, from[100005] = {};
vector<vii> g(100005);
void dfs(int u, int x, int val) {
	num[u] = x;
	for(ii cur : g[u]) {
		if(!num[cur.ss] && cur.ff < val) dfs(cur.ss, x, val);
	}
}	
int main() {
	SYNC;
	cin >> n >> m >> x;
	FOR0(i, m) {
		cin >> a >> b >> w;
		if(w > x) continue;
		g[a].pb(mp(w,b));
		g[b].pb(mp(w,a));
	}
	FOR0(i,n+1) dist[i] = 2*INF;
	int cnt = 0;
	FOR(start,1,n+1) {
		if(num[start]) continue;
		cnt++; dfs(start, cnt, 2*INF);
	}
	FOR(i,1,n+1) from[num[i]]++;
	ll tot = 0;
	FOR(i,1,cnt+1) tot += ((ll)from[i]*((ll)from[i]-1))/2;
	FOR0(i,n+1) dist[i] = 2*INF;
	cnt = 0;
	memset(num,0,sizeof num);
	memset(from,0,sizeof from);
	FOR(start,1,n+1) {
		if(num[start]) continue;
		cnt++; dfs(start, cnt, x);
	}
	FOR(i,1,n+1) from[num[i]]++;
	FOR(i,1,cnt+1) tot -= ((ll)from[i]*((ll)from[i]-1))/2;
	cout << tot;
}