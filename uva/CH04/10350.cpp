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

int main() {
	string name;
	int n, m;
	int tim[122][17][17], dp[122][17];
	while(cin >> name) {
		cout << name << endl;
		scanf("%d%d",&n,&m);
		FOR0(i,n-1) {
			FOR0(j, m) {
				FOR0(k, m) {
					scanf("%d", &tim[i][j][k]);
				}
			}
		}
		FOR0(i, m) dp[n-1][i] = 0;
		FORD(i,0,n-1) {
			FOR0(j,m) {
				int val = INF;
				FOR0(k, m) val = min(val,dp[i+1][k]+tim[i][j][k]);
				dp[i][j] = val;
			}
		}
		cout << 2*(n-1) + (*min_element(dp[0],dp[0]+m)) << endl;
	}
}