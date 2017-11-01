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
int n, s;
ll a[100001], b[100001];
int poss(int cnt) {
	ll sum = 0;
	FOR0(i, n) b[i] = a[i] + (ll)cnt*((ll)i+1);
	sort(b, b+n);
	FOR0(i, cnt) sum += b[i];
	if(sum <= (ll)s) return sum; else return -1;
}
int main() {
	SYNC;
	cin >> n >> s;
	FOR0(i, n) cin >> a[i];
	int l = 0, r = n, ans = 0, cost = 0;
	while( l <= r) {
		int mid = (l+r)/2;
		int tmp = poss(mid);
		if(tmp != -1) {ans = mid; cost = tmp; l = mid+1;}
		else r = mid - 1;
	}
	cout << ans << " " << cost;
}