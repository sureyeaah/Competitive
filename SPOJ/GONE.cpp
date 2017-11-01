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
int sumdp[11][101], dp[11][10][101];
int query(string x, int offset) {
	if(!x.length()) return 0;
	int ans = 0;
	FOR(i, 0, x[0]-'0') ans += dp[x.length()][i][offset];
	ans += query(x.substr(1), offset + x[0]-'0');
	return ans;
}
bitset<101> bs;
int check(int i) {
	string x = to_string(i);
	int sum = 0;
	FOR0(j, x.length()) sum += x[j] - '0';
	if(bs[sum]) return 1;
	return 0;
}
int brute(int r, int l) {
	int ans = 0;
	FOR(i,l,r+1) {
		string x = to_string(i);
		int sum = 0;
		FOR0(j, x.length()) sum += x[j] - '0';
		if(bs[sum]) ans++;
	}
	return ans;
}
int brute(int r) {return brute(1,r);}
int main() {
	int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	FOR0(i, 25) bs[primes[i]] = 1;
	memset(dp,0,sizeof dp);
	sumdp[0][0] = 1;
	FOR(len,1,10) {
		FOR(digit,0,10) {
			FOR(sum,digit,100) {
				sumdp[len][sum] += sumdp[len-1][sum-digit];
				FOR(offset, 0, 100-sum)
					if(bs[sum+offset]) dp[len][digit][offset] += sumdp[len-1][sum-digit];
			}
		}
	}
	int c,f,t;
	scanf("%d", &c);
	while(c--) {
		scanf("%d %d", &f, &t);
		//cout << query(to_string(t+1), 0) << " " << query(to_string(f-1), 0) << "---" << brute(t) << " " << brute(f) << endl;
		printf("%d\n", query(to_string(t), 0)-query(to_string(f), 0)+check(t));
	}
}