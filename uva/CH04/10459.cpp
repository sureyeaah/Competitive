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
int n, k, x, dist[5000+10],maxReach[5000+10];
vvi graph(5000+10);
int dfs(int u, int prev) {
    dist[u] = dist[prev] + 1;
    int ret = 0;
    repi(i, graph[u])
        if((*i) != prev)
            ret = max(ret,dfs(*i, u)+1);
    return (maxReach[u] = ret);
}
int main() {
    while (scanf("%d", &n) != EOF) {
        FOR(u,1,n+1) {
            graph[u].clear();
            scanf("%d", &k);
            while(k--) {
                scanf("%d", &x);
                graph[u].pb(x);
            }
        }
        dist[0] = -1;
        dfs(n/2,0);
        int farthest = max_element(dist+1, dist+n+1) - dist;
        int diameter = dfs(farthest, 0);
        int half = (diameter+1)/2;
        vi best;
        FOR(i,1,n+1) {
            if(maxReach[i] == half || maxReach[i] == (diameter - half)) {
                best.pb(i);
            }
        }
        vi worst(n+1, false);
        dfs(best[0],0);
        FOR(i,1,n+1) {
            if(dist[i] == half) {
                worst[i] = true;
            }
        }
        if(diameter %2 == 1) {
            dfs(best[1],0);
            FOR(i,1,n+1) {
                if(dist[i] == half) {
                    worst[i] = true;
                }
            }
        }
        printf("Best Roots  :");
        if(diameter%2 == 0) printf(" %d\n",best[0]);
        else printf(" %d %d\n",best[0],best[1]);
        printf("Worst Roots :");
        FOR(i,1,n+1) {
            if(worst[i]) printf(" %d", i);
        }
        printf("\n");
    }
}
