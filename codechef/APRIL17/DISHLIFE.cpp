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

int main() {
	int t,n,k,p,x;
	scanf("%d", &t);
	ll cnt[100000 + 5];
	vvi v(100000 + 5);
	while(t--) {
		scanf("%d%d",&n,&k);
		FOR0(i, n) v[i].clear();
		FOR0(i, k+1) cnt[i] = 0;
		FOR0(i, n) {
			scanf("%d", &p);
			while(p--) {
				scanf("%d", &x);
				cnt[x]++;
				v[i].pb(x);
			}
		}
		int ans = 0;
		FOR0(i, n) {
			int common = v[i].size();
			repi(j, v[i]) if(cnt[*j]>1) common--;
			if(!common) ans = 1;
		}	
		FOR(i,1,k+1) if(!cnt[i]) ans = -1;
		if(!ans) printf("all\n");
		else if(ans+1) printf("some\n");
		else printf("sad\n");
	}
}