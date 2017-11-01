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
	int n, m, k, x, y;
	bool v[20002];
	scanf("%d%d",&n,&m);
	bool ans = false;
	FOR0(i, m) {
		bool curr_ans = false;
		scanf("%d", &k);
		memset(v, false, sizeof v);
		FOR0(j, k) {
			scanf("%d", &x);
			if(x < 0) {y = -x; x = n - x;}
			else y = n+x;
			if(v[y]) curr_ans = true;
			else v[x] = true;
		}
		if(!curr_ans) ans = true;
	}
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}