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
#define toint(c) ((c>='A')?(10+(c-'A')):(c-'0'))
int main() {
	char input[20];
	int n;
	ll val[20][20];
	while(scanf("%s",input)!=EOF) {
		n = strlen(input);
		memset(val,0,sizeof val);
		FOR(j,1,n+1) val[1][j] = 1;
		FOR(i, 1, n+1) {
			if(input[i-1]!='?') {
				ll tmp = val[i][toint(input[i-1])];
				FOR(j,1,n+1) val[i][j] = 0;
				val[i][toint(input[i-1])] = tmp;
			}
			FOR(j,1,n+1) FOR(k,1,j-1) val[i+1][k]+= val[i][j];
			FOR(j,1,n+1) FOR(k,j+2,n+1) val[i+1][k]+= val[i][j];
		}
		ll ans = 0;
		FOR(i,1,n+1) ans += val[n][i];
		printf("%lld\n",ans);
	}
}