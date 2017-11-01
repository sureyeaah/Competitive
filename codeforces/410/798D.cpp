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
int n, a[100005], b[100005], c[100005];
bool comp(int l, int r) {
	return a[l] > a[r];
}
int main() {
	SYNC;
	cin >> n;
	memset(c,0,sizeof c);
	FOR0(i, n) cin >> a[i];
	FOR0(i, n) cin >> b[i];
	FOR0(i, n) c[i] = i;
	sort(c, c+n, comp);
	cout << n/2 + 1 << endl;
	if(n&1) cout << c[0]+1 << " ";
	else cout << (b[c[0]] >= b[c[1]] ? c[1]: c[0])+1 << " ";
	for(int i = n%2; i < n; i+=2) {
		if(b[c[i]] >= b[c[i+1]]) cout << c[i]+1 << " ";
		else cout << c[i+1]+1 << " ";
	}
}