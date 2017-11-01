#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
	SYNC;
	int n, p[200005], a[200005], b[200005], m, c[200005];
	bitset<200005> taken;
	taken.reset();
	cin >> n;
	FOR0(i, n) cin >> p[i];
	FOR0(i, n) cin >> a[i];
	FOR0(i, n) cin >> b[i];
	cin >> m;
	FOR0(i, m) cin >> c[i];
	priority_queue<ii, vii, greater<ii> > pq[4];
	FOR0(i, n) pq[a[i]].push(mp(p[i],i));
	FOR0(i, n) if(a[i] != b[i]) pq[b[i]].push(mp(p[i],i));
	FOR0(i, m) {
		if(pq[c[i]].empty()) {
			cout << "-1 ";
			continue;
		}
		ii curr;
		do {
			curr = pq[c[i]].top(); pq[c[i]].pop();
		} while(taken[curr.ss] && !pq[c[i]].empty());
		if(taken[curr.ss]) {
			cout << "-1 ";
			continue;
		}
		cout << curr.ff << " ";
		taken[curr.ss] = 1;
	}
}