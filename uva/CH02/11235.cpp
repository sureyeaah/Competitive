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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define left(p) ((p)<<1)
#define right(p) (((p)<<1) + 1)
int n, q, a[100005], freq[100005], x, currLen, st[400020], endPoint[100005];
int build(int p, int l, int r) {
	if(l == r) {return st[p] = freq[l];}
	return st[p] = max(build(left(p),l,(l+r)/2), build(right(p), (l+r)/2 + 1, r));
}
int query(int p, int l, int r, int i, int j) {
	if(l >=i && r <= j) return st[p];
	if(l > j || r < i) return -INF;
	return max(query(left(p),l,(l+r)/2,i,j), query(right(p),(l+r)/2+1,r,i,j));
}
int main() {
	while(scanf("%d", &n) && n) {
		scanf("%d",&q);
		a[0] = -INF; currLen = 0; a[n+1] = INF;
		FOR(i, 1, n+1) scanf("%d", a+i);
		FOR(i, 1, n+2) {
			if(a[i] == a[i-1]) currLen++;
			else {
				FOR(j,i-currLen,i) {freq[j] = currLen; endPoint[j] = i-1;}
				currLen = 1;
			}
		}
		build(1,1,n);
		while(q--) {
			int i, j;
			scanf("%d%d",&i,&j);
			int ans;
			if(j>endPoint[i]) {
				ans = max(endPoint[i]-i+1, freq[j]-endPoint[j]+j);
				i = endPoint[i]+1;
				j = endPoint[j]-freq[j];
				if(i<j) ans = max(ans, query(1,1,n,i,j));
			}
			else ans = j-i+1;
			printf("%d\n", ans);
		}
	}	
}