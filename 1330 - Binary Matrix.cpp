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
int t, n, m, res[105][105], S, T, x, par[105], f;
void augment(int u, int minEdge) {
	if(u == S) f = minEdge;
	else if (par[u] != -1) {augment(par[u], min(minEdge, res[par[u]][u]));
							res[par[u]][u] -= f; res[u][par[u]] += f;}
}
int main() {
	scanf("%d", &t);
	FOR(caseNum,1,t+1) {
		scanf("%d%d", &m, &n);
		memset(res,0,sizeof res);
		S = m+n; T = S+1;
		FOR0(i, m) {
			scanf("%d", &res[S][i]);
		}
		FOR0(i, n) {
			scanf("%d", &res[m+i][T]);
		}
		FOR0(i, m) FOR0(j, n) res[i][m+j] = 1;
		while(1) {
			queue<int> q; q.push(S);
			f = 0;
			memset(par,-1,sizeof par); par[S] = S;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u == T) break;
				if(u == S) {
					FORD(v, 0, m) {
						if(res[u][v] && par[v] == -1) {
							q.push(v); par[v] = u;
						}
					}
				}
				else {
					FOR(v, T, T+1) {
						if(res[u][v] && par[v] == -1) {
							q.push(v); par[v] = u;
						}
					}
					FOR(v, 0, T) {
						if(res[u][v] && par[v] == -1) {
							q.push(v); par[v] = u;
						}
					}
				}
			}
			augment(T, INF);
			if(!f) break;
		}
		printf("Case %d:", caseNum);
		bool possible = true;
		FOR0(i, n) if(res[m+i][T]) possible = false;
		if(*max_element(res[S], res[S]+m) || !possible) printf(" impossible\n");
		else {
			printf("\n");
			FOR0(i, m) {
				FOR0(j, n) printf("%d", !res[i][m+j]);
				printf("\n");
			}
		}
	}
}