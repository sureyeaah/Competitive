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
	int a,b,graph[100 + 1][100 + 1], num[100 + 10], caseNum = 1;
	bool items[100 + 10];
	while(scanf("%d%d", &a, &b) && a && b) {
		memset(items, false, sizeof items);
		FOR0(i, 101) 
			FOR0(j, 101) 
				graph[i][j] = INF;
		FOR0(i, 101) graph[i][i] = 0;
		int numItems = 0;

		do {
			if(!items[a]) {
				items[a] = true;
				num[a] = numItems++;
			}
			if(!items[b]) {
				items[b] = true;
				num[b] = numItems++;
			}
			graph[num[a]][num[b]] = 1;
		} while(scanf("%d%d", &a, &b) && a && b);
		FOR0(k,numItems)
			FOR0(i,numItems)
				FOR0(j,numItems)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		int sum = 0;
		FOR0(i,numItems)
			FOR0(j,numItems)
				if(graph[i][j] < INF) sum += graph[i][j];
		printf("Case %d: average length between pages = %.3f clicks\n", caseNum++, (double)(sum)/(double)(numItems*(numItems-1)));
	}
}