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
#define S 36
#define T 37
int adj[40][40], p[40], f;
char c, num; int users;
bool done = false;
string s;
void augment(int v, int minEdge) {
	if(v == S) f = minEdge;
	else if(p[v] != -1) {
		augment(p[v], min(minEdge, adj[p[v]][v]));
		adj[p[v]][v] -= f;
		adj[v][p[v]] += f;
	}
}
int main() {
	SYNC;
	while(!done) {
		int todo = 0;
		memset(adj, 0, sizeof adj);
		FOR0(i, 10) adj[S][i] = 1;
		getline(cin, s);
		done = cin.eof();
		while(s.length()) {
			istringstream iss(s);
			iss >> c >> users;
			adj[c-'A'+10][T] = users;
			todo += users;
			while(iss >> num, num != ';') {
				adj[num-'0'][c-'A'+10] = 1;
			}
			if(done) break;
			getline(cin, s);
			done = cin.eof();
		}
		done = cin.eof();
		// flow
		int mf = 0;
		while(1) {
			queue<int> q; q.push(S);
			f = 0;
			FOR0(i, 40) p[i] = -1;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u == T) break;
				FOR0(i, T+1) {
					if(adj[u][i] && p[i] == -1) {
						p[i] = u;
						q.push(i);
					}
				}
			}
			if(p[T] == -1) break;
			augment(T, INF);
			if(!f) break;
			mf += f;
		}
		if(todo != mf) printf("!\n");
		else {
			FOR0(i, 10) {
				FOR0(j, 26) {
					if(adj[j+10][i] == 1) {
						printf("%c",'A'+j);
						break;
					}
					if(j == 25) printf("_");
				}
			}
			printf("\n");
		}
	}
}