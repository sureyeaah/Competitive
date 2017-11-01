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
    int cases,n,m,s,t,x,y,w;
    vector<vii> graph(20000 + 10);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    int seconds[20000 + 10];
    scanf("%d", &cases);
    FOR(caseNumber, 1, cases+1) {
        scanf("%d%d%d%d",&n,&m,&s,&t);
        FOR0(i, n) graph[i].clear();
        FOR0(i, n) seconds[i] = INF;
        FOR0(i,m) {
            scanf("%d%d%d",&x,&y,&w);
            graph[x].pb(mp(w,y));
            graph[y].pb(mp(w,x));
        }
        seconds[s] = 0;
        pq.push(mp(0,s));
        while(!pq.empty()) {
            ii curr = pq.top(); pq.pop();
            int sec = curr.first, u = curr.second;
            if(sec > seconds[u]) continue;
            repi(i, graph[u]) {
                int d = (*i).first, v = (*i).second;
                if(seconds[v] <= seconds[u] + d) continue;
                seconds[v] = min(seconds[v], seconds[u] + d);
                pq.push(mp(seconds[v],v));
            }
        }
        printf("Case #%d: ", caseNumber);
        if(seconds[t] < INF) printf("%d\n", seconds[t]);
        else printf("unreachable\n");
    }
}