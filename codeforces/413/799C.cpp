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
typedef pair<ii,int> iii;
int main() {
	SYNC;
	int n,coins[2],sz[2];
	int b,p; char type;
	cin >> n >> coins[0] >> coins[1];
	vector<iii> ps[2], bs[2];
	int ans = 0;
	FOR0(i, n) {
		cin >> b >> p >> type;
		ps[type-'C'].pb(mp(mp(-p,-b),i));
		bs[type-'C'].pb(mp(mp(-b,p),i));
	}
	FOR0(i, 2) sz[i] = ps[i].size();

	sort(ps[0].begin(), ps[0].end()); sort(bs[0].begin(), bs[0].end());
	sort(ps[1].begin(), ps[1].end()); sort(bs[1].begin(), bs[1].end());
	
	vi price[2];
	FOR0(i, 2) FOR0(j, sz[i]) price[i].pb(ps[i][j].ff.ff);
	
	vii bestb[2], bestb2[2];
	FOR(j,0,2) {
		bestb[j].resize(sz[j] + 1); bestb2[j].resize(sz[j] + 1);
		bestb[j][sz[j]] = mp(0,INF); bestb2[j][sz[j]] = mp(0,INF+1);
		FORD(i,0,sz[j]) {
			if(bestb[j][i+1].ff <= -ps[j][i].ff.ss) {
				bestb2[j][i] = bestb[j][i+1];
				bestb[j][i] = mp(-ps[j][i].ff.ss, ps[j][i].ss);
			} else if(bestb2[j][i+1].ff <= -ps[j][i].ff.ss) {
				bestb[j][i] = bestb[j][i+1];
				bestb2[j][i] = mp(-ps[j][i].ff.ss, ps[j][i].ss);
			}  
			else {
				bestb2[j][i] = bestb2[j][i+1];
				bestb[j][i] = bestb[j][i+1];
			}
		}
	}

	FOR0(coin, 2) {
		repi(i, bs[coin]) {
			if(i->ff.ss > coins[coin]) continue;
			int x = lower_bound(price[coin].begin(), price[coin].end(), i->ff.ss-coins[coin]) - price[coin].begin();
			if(x < sz[coin]) {
				if(bestb[coin][x].ss != i->ss) ans = max(ans, bestb[coin][x].ff - i->ff.ff);
				else if(bestb2[coin][x].ss < INF) ans = max(ans, bestb2[coin][x].ff - i->ff.ff);
			}
			int y = lower_bound(price[1-coin].begin(), price[1-coin].end(), -coins[1-coin]) - price[1-coin].begin();
			if(y < sz[1-coin])
				ans = max(ans, bestb[1-coin][y].ff - i->ff.ff);
		}
	}
	cout << ans << endl;
}