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
#define index(x) ((x<0)?50-(x):(x))
int sumdp[10][105], dp[10][10][105];
int query(string x, int offset) {
	int ret = 0;
	if(!x.length()) return 0;
	FOR0(i, x[0]-'0') {
		ret += dp[x.length()][i][index(offset)];
	}
	ret += query(x.substr(1),offset + ((x.length() & 1) ? -(x[0]-'0'): (x[0]-'0')));
	return ret;
}
/*
int check(int start, int end) {
	int ret = 0;
	FOR(i,start,end+1) {
		string x = to_string(i);
		int add = 0;
		FOR0(i,x.length()) add += (i&1) ? x[x.length()-i-1]-'0': -x[x.length()-i-1]+'0';
		if(add == 1) ret++;
	}
	return ret;
}*/
int main() {
	sumdp[0][0] = 1;
	FOR(len,1,10) {
		FOR(digit,0,10) {
			FOR(sum,-49,51) {
				int newSum = (len&1) ? sum-digit : sum + digit;
				if(newSum>=-50 && newSum<=50) {
					sumdp[len][index(newSum)] += sumdp[len-1][index(sum)];
					FOR(offset,-50,51) if(offset+newSum==1) dp[len][digit][index(offset)] += sumdp[len-1][index(sum)];
				}
			}
		}
	}
	int t, from, to;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &from, &to);
		printf("%d\n",query(to_string(to+1),0)-query(to_string(from),0));
	}
}