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
int n,m,r[100005],num,x,p[400000 + 10];
vvi room(100005);
int findSet(int i) {
	return p[i]==i ? i : (p[i] = findSet(p[i]));
}
bool sameSet(int i, int j) {
	return findSet(i)==findSet(j);
}
void unite(int i, int j) {
	int x = findSet(i), y = findSet(j);
	if(x != y) p[x] = y;
}
int main() {
	SYNC;
	cin >> n >> m;
	FOR0(i, 2*m+5) p[i] = i;
	FOR0(i, n) cin >> r[i+1];
	FOR0(i,m) {
		cin >> num;
		while(num--) {
			cin >> x; room[x].pb(i);
		}
	}
	FOR(i, 1, n+1) {
		int a = room[i][0]<<1, b=room[i][1]<<1;
		if(r[i]) {
			unite(a,b); unite(a^1,b^1);
		} else {
			unite(a,b^1); unite(b,a^1);
		}
	}
	int ans = 1;
	FOR0(i,m) {
		if(sameSet(i<<1,(i<<1)^1)) ans = 0;
	}
	cout << (ans?"YES":"NO") << endl;

}