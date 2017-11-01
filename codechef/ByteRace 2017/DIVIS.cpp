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
#define MOD 1000000007
int main() {
	int n,m,d,l,r,q,dp[1005][52];
	string s="",str="";
	scanf("%d%d",&m,&d);
	while(getchar() != '\n') {}
	FOR0(i, m) {
		cin >> str;
		s += str;
	}
	n = s.length();
	memset(dp,0,sizeof dp);
	dp[0][0] = 1;
	FOR0(pos,n) {
		FORD(len,0,pos+1) {
			FOR0(k,d) {
				dp[len+1][(k*10 + (s[pos]-'0'))%d] = (dp[len+1][(k*10 + (s[pos]-'0'))%d]+dp[len][k])%MOD;
			}
		}
	}
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l][r]);
	}
}