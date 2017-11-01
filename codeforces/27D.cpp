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
#define NOT(x) (x^1)
bitset<410> vis, vis2;
vvi graph(210);
int impos;
int n, m, a[105], b[105], inroad[110];
int dfs(int u) {
	vis[u] = 1;
	for(int v : graph[u]) {
		if(vis[v]) continue;
		int ret = dfs(v);
		if(inroad[u>>1] == -1) inroad[u>>1] = ret;
		else if(ret == inroad[u>>1]) impos = 1;
	}
	return inroad[u>>1];
}
void dfs2(int u, int val) {
	vis2[u] = 1;
	if(inroad[u>>1] == -1) inroad[u>>1] = val;
	else if(inroad[u>>1] != val) impos = 1;
	for(int v : graph[u]) if(!vis2[v]) dfs2(v, !val);
}
int main() {
	SYNC;
	cin >> n >> m;
	FOR0(i,m) {
		cin >> a[i] >> b[i];
		if(a[i] > b[i]) swap(a[i], b[i]);
	}
	impos = 0;
	FOR0(i,m) {
		FOR0(j, m) {
			if(i != j && b[j] > b[i] && a[j] > a[i] && a[j] < b[i]) {
				graph[i<<1].pb(NOT(j<<1)); graph[NOT(i<<1)].pb(j<<1);
				graph[j<<1].pb(NOT(i<<1)); graph[NOT(j<<1)].pb(i<<1);
			}
		}
	}
	FOR0(i, 2*m + 5) inroad[i] = -1; 
	FOR0(i,m) {
		if(!vis[i<<1]) {
			int ret = dfs(i<<1);
			dfs2(i<<1,(ret==-1?0:ret));
		}
	}
	if(impos) cout << "Impossible" << endl;
	else FOR0(i, m) cout << (inroad[i] ? 'i': 'o');
}