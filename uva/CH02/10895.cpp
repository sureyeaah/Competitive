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
	int n,m,col[1000+10],cols,x;
	vector<vii> transpose(10000+10);
	while(scanf("%d%d",&m,&n) != EOF) {
		FOR0(i,n+1) transpose[i].clear();
		FOR(row,1,m+1) {
			scanf("%d",&cols);
			FOR0(i, cols)
				scanf("%d",col+i);
			FOR0(i,cols) {
				scanf("%d", &x);
				transpose[col[i]].pb(mp(row,x));
			}
		}
		printf("%d %d\n",n,m);
		FOR(col,1,n+1) {
			printf("%d",transpose[col].size());
			repi(i,transpose[col]) printf(" %d",(*i).first);
			printf("\n");
			if(transpose[col].size())printf("%d",transpose[col][0].second);
			FOR(i,1,transpose[col].size()) printf(" %d",transpose[col][i].second);
			printf("\n");
		}
	}
}