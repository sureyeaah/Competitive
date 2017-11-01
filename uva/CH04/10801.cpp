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
typedef pair<int, ii> iii;
int main() {
	int n, k, t[6], x, seconds[100 + 10][6];
	bool graph[100 + 10][6];
	string s;
	priority_queue <iii> pq;
	while(cin >> n >> k) {
		FOR0(i, n) scanf("%d", t+i);
		while(getchar() != '\n') {}
		memset(graph, false, sizeof graph);
		FOR0(i, n) {
			getline(cin, s);
			istringstream iss (s);
			while(iss >> x)
				graph[x][i] = true;
		}
		FOR0(i, 100) FOR0(j, n) seconds[i][j] = INF;
		FOR0(i, n) {
			if(graph[0][i]) {
				pq.push(mp(0, mp(0, i)));
				seconds[0][i] = 0;
			}
		}
		while(!pq.empty()) {
			iii curr = pq.top(); pq.pop();
			int d = -curr.first, u = curr.second.first, prevEl = curr.second.second;
			if(seconds[u][prevEl] < d) continue;
			FOR0(v, 100) {
				if(v == u || !graph[v][prevEl]) continue;
				else if(seconds[v][prevEl] > seconds[u][prevEl] + t[prevEl]*abs(v-u)){
					seconds[v][prevEl] = seconds[u][prevEl] + t[prevEl]*abs(v-u);
					pq.push(mp(-seconds[v][prevEl], mp(v, prevEl)));
				}
			}
			FOR(nextEl,0,n) {
				if(graph[u][nextEl] && seconds[u][prevEl] + 60 < seconds[u][nextEl]) {
					seconds[u][nextEl] = seconds[u][prevEl] + 60;
					pq.push(mp(-seconds[u][nextEl], mp(u, nextEl)));
				}
			}
		}
		int ans = *min_element(seconds[k], seconds[k]+n);
		if(ans < INF) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
}