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
#define NOT(x) ((x)^1)
int n,m,a,b,c,p[205];
int findSet(int i) {
	return p[i] == i ? i : (p[i] = findSet(p[i]));
}
bool sameSet(int i, int j) {
	return findSet(i)==findSet(j);
}
void unite(int i, int j) {
	int x=findSet(i), y = findSet(j);
	if(x != y) p[x] = y;
}
int main() {
	SYNC;
	int ans[210];
	cin >> n >> m;
	FOR0(i, 2*n + 2) ans[i] = -1;
	FOR0(i, 2*n + 2) p[i] = i;
	FOR0(i,m) {
		cin >> a >>b >> c;
		a <<= 1; b<<=1;
		if(c) {
			unite(a,b); unite(NOT(a),NOT(b));
		} else {
			unite(a,NOT(b)); unite(b,NOT(a));
		}
	}
	FOR(i,1,n+1) {
		if(sameSet(i<<1,NOT(i<<1))) {
			cout << "Impossible" << endl; return 0;
		} 
	}
	FOR(i,1,n+1) {
		int x = findSet(i<<1), y = findSet(NOT(i<<1));
		if(ans[x]==-1 && ans[y]==-1) {
			ans[x] = 0; ans[y] = 1;
		} else if(ans[x]==-1) ans[x] = !ans[y];
		else if(ans[y] == -1) ans[y] = !ans[x];
		ans[i<<1] = ans[x]; ans[NOT(i<<1)] = ans[y];
	}
	int days = 0;
	FOR(i,1,n+1) if(ans[i<<1]) days++;
	cout << days << endl;
	FOR(i,1,n+1) if(ans[i<<1]) cout << i << " ";
}