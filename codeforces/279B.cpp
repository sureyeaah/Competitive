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
int n,t,sum[100001];
bool check(int x) {
	FOR0(i, n-x+1) {
		if(sum[i+x] - sum[i] <= t) return true;
	}
	return false;
}
int main() {
	scanf("%d%d", &n, &t);
	sum[0] = 0;
	FOR(i, 1, n+1) {
		scanf("%d", sum+i);
		sum[i] += sum[i-1];
	}
	int l = 0, r = n, mid;
	while(l < r) {
		mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d\n",l);
}