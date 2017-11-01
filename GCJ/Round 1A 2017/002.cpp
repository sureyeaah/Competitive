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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int t, n, p, r[55], q[55][55];
ii servings[55][55];
/*
bool possible(int x) {
	int ret = 0;
	FOR0(i, n) {
		FORD(j,0,p) {

		}
	}
}*/
int main() {
	SYNC;	
	cin >> t;
	FOR(caseNum,1,t+1) {
		cin >> n >> p;
		FOR0(i, n) cin >> r[i];
		FOR0(i, n) FOR0(j, p) cin >> q[i][j];
		int ans = 0;
		FOR0(i, n) FOR0(j, p) {
			int start = (int)ceil((q[i][j]*9.0)/(10.0*r[i]));
			int end = (int)((q[i][j]*11.0)/(10.0*r[i]));
			//cout << start << " " << end << endl;
			servings[i][j] = mp(start, end);
		}
		FOR0(i, n) sort(servings[i], servings[i]+p);
		if(n==1) {
			ans = 0;
			FOR0(i, p) if(servings[0][i].ss || servings[0][i].ff) ans++;
		} else if(n == 2) {
			FOR(x,1,1<<(p)) {
				bitset<8> bs;
				FORD(i,0,p) {
					if(x&(1<<i)) {
						FORD(j,0,p) {
							if(!bs[j] && ((servings[0][i].ff<=servings[1][j].ss && servings[0][i].ss)|| (servings[1][j].ff<=servings[0][i].ss && servings[1][j].ss))) {bs[j]=1; break;}
						}
					}
				}
				ans = max((int)bs.count(), ans);
			}
		}
		/*int left = 0, right = n-1;
		while(left <= right) {
			int mid = (left+right+1) >> 1;
			if(possible(mid)) {
				ans = max(ans, mid);
				left = mid;
			} else right = mid - 1;
		}*/
		cout << "Case #" << caseNum << ": " << ans << endl;
	}
}