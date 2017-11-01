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
#define maxn 100005

int par[maxn];
set<int> s[maxn];
int findSet(int i) {
	return i == par[i] ? i: (par[i] = findSet(par[i]));
}
bool sameSet(int i, int j) {
	return findSet(i)==findSet(j);
}
void unite(int i, int j) {
	int x= findSet(i), y = findSet(j);
	if(x != y) {
		if(SZ(s[x]) < SZ(s[y])) swap(x,y);
		par[y] = x;
		s[x].insert(s[y].begin(), s[y].end());
		s[y].clear();
	}
}
int main() {
	SYNC;
	bitset<maxn> vis;
	int n,m,q,t[maxn],qx[maxn],qy[maxn],qk[maxn],lq[maxn], rq[maxn], ans[maxn];
	pair<int, ii> e[maxn];
	vvi check(maxn);
	cin >> n >> m >> q;
	FOR(i,1,n+1) {
		cin >> t[i];
	}
	FOR0(i, m) cin >> e[i].ss.ff >> e[i].ss.ss >> e[i].ff;
	sort(e,e+m);
	FOR0(i,q) {
		lq[i] = 0;
		rq[i] = m-1;
	}
	FOR0(i, q) cin >> qx[i] >> qy[i] >> qk[i];
	FOR0(i, q) ans[i] = -1;
	int done = false;
	while(!done) {
		done = true;
		FOR0(i, q) {
			if(lq[i] <= rq[i]) {
				done = false;
				check[(lq[i]+rq[i]) >> 1].pb(i);
			}
		}
		FOR(i,1,n+1) {
			s[i].clear();
			s[i].insert(t[i]);
			par[i] = i;
		}
		int cur = 0;
		FOR0(i, m) {
			if(SZ(check[i])) {
				while(cur <= i) {
					unite(e[cur].ss.ff, e[cur].ss.ss);
					cur++;
				}
				for(int cq: check[i]) {
					if(sameSet(qx[cq],qy[cq]) && SZ(s[findSet(qx[cq])]) >= qk[cq]) {
						rq[cq] = i-1;
						ans[cq] = e[i].ff;
					} else lq[cq] = i+1; 
				}
				check[i].clear();
			}
		}
	}
	FOR0(i, q) cout << ans[i] << endl;
}