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
bool visited[26];
int t;
string line;
char c1, c2;
vvi graph(26);
void dfs(int u) {
	visited[u] = true;
	repi(i,graph[u]) if(!visited[*i]) dfs(*i);
}
int main() {
	scanf("%d", &t);
	while(getchar() != '\n') {}
	while(t--) {
		FOR0(i,26) graph[i].clear();
		int trees = 0, acorns = 0;
		memset(visited,false,sizeof visited);
		while(scanf("%c",&c1) && c1!='*') {
			scanf("%c%*c%c",&c1,&c2);
			int u = c1-'A', v=c2-'A';
			graph[u].pb(v);
			graph[v].pb(u);
			while(getchar() != '\n') {}
		}
		while(getchar() != '\n') {}
		getline(cin,line);
		FOR0(i,line.length()) {
			if(!visited[line[i]-'A']) {
				dfs(line[i]-'A');
				if(graph[line[i]-'A'].size())trees++;
				else acorns++;
			}
			i++;
		}
		printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
	}
}