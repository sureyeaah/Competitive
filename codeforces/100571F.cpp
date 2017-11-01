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
int n,a,b,c,xx,yy; ll x,y;
map<ll,int> coord;
int p[400000+5],r[400000+5];
int findSet(int i) {
	return(p[i] == i) ? i: (p[i] = findSet(p[i]));
}
bool sameSet(int i, int j) {
	return findSet(i)==findSet(j);
}
void unionSet(int i, int j) {
	int x = findSet(i), y = findSet(j);
	if(x!=y) {
		p[x] = y;
	}
}
int main() {
	SYNC; c=1;
	cin >> n;
	int ans = 1;
	//FOR0(i, 400000+5) r[i] = 0;
	FOR0(i, 400000+5) p[i] = i;
	FOR0(i, n) {
		cin >> x >> y >> a >> b;
		if(ans) {
			xx = (coord[x]) ? coord[x]:  (coord[x] = c++);
			yy = (coord[-y]) ? coord[-y]:  (coord[-y] = c++);
			xx<<=1; yy<<=1;
			if(a == b) {
				unionSet(xx,yy);
				unionSet(NOT(xx),NOT(yy));
			}
			else {
				unionSet(xx,NOT(yy));
				unionSet(NOT(xx),yy);
			}
			if(!sameSet(xx,NOT(xx)) && !sameSet(yy,NOT(yy))) cout << "Yes" << endl;
			else {
				ans = 0;
				cout << "No" << endl;
			}
		} else cout << "No" << endl;
	}

}