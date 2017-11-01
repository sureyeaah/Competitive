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
typedef pair<int,ii> iii;
int main() {
	int m, numLang, sInd, dInd, dist[5000+1][27];
	string o, d, i1, i2, p;
	map<string, int> lang;
	vector<vector<iii>> graph(5000+1);
	priority_queue<iii> pq;
	while(cin >> m && m) {
		numLang = 0;
		cin >> o >> d;
		lang.clear();
		lang[o] = numLang++;
		lang[d] = numLang++;
		graph[0].clear(); graph[1].clear();
		FOR0(i, m) {
			cin >> i1 >> i2 >> p;
			if(!lang.count(i1)) {graph[numLang].clear(); lang[i1] = numLang++; }
			if(!lang.count(i2)) {graph[numLang].clear(); lang[i2] = numLang++; }
			sInd = lang[i1];
			dInd = lang[i2];
			graph[sInd].pb(mp(dInd, mp(p.length(),p[0]-'a')));
			graph[dInd].pb(mp(sInd, mp(p.length(),p[0]-'a')));
		}
		// FOR0(i, numLang) sort(graph[i].begin(), graph[i].end(), greater<iii>());
		FOR(i,0,numLang) FOR0(j,26) dist[i][j] = INF;
		dist[0][26] = 0;
		pq.push(mp(0, mp(0,26)));
		while(!pq.empty()) {
			iii curr = pq.top(); pq.pop();
			int d = -curr.first, u = curr.second.first, prevC = curr.second.second;
			if(dist[u][prevC] < d) continue;
			repi(i, graph[u]) {
				int v = (*i).first, nextC = (*i).second.second, w = (*i).second.first;
				if(nextC != prevC && dist[u][prevC] + w < dist[v][nextC]) {
					dist[v][nextC] = d + w;
					pq.push(mp(-dist[v][nextC], mp(v, nextC)));
				}
			}
		}
		int ans = *min_element(dist[1], dist[1] + 26);
		if(ans != INF) cout << ans << endl;
		else cout << "impossivel" << endl;
	}
}