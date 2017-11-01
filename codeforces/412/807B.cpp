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
	int p, x, y;
	cin >> p >> x >> y;
	int ans, output = 0, answer = INF;
	if(1) {
		ans = x;
		while(ans < y) ans += 50;
		while(!output) {
			int i = (ans/50) % 475;
			FOR0(j,25) {
				i = (i*96 + 42) %475;
				if(p == 26+i) {output = ans; break;}
			}
			ans += 50;
		}
		output = ceil(abs(output-x)/100.0);
		answer = min(output, answer);
	} 
	if(x >= y){
		ans = x;
		output = -1;
		while(ans >= y) {
			int i = (ans/50) % 475;
			FOR0(j,25) {
				i = (i*96 + 42) %475;
				if(p == 26+i) {if((abs(output-x))%100) answer = 0; else answer = min(1,answer);}
			}
			ans -= 50;
		}
	}
	cout << answer << endl;
}