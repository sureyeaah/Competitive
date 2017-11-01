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
    int e,n,x;
    scanf("%d", &e);
    vvi graph(e); 
    FOR0(i, e) {
        scanf("%d", &n);
        while(n--)  {
            scanf("%d",&x);
            graph[i].pb(x);
        }
    }
    int t;
    scanf("%d", &t);
    int day[2500 + 10], boom[2500+10];
    while(t--) {
        int source, maxBoom = 0, boomDay = INF;
        FOR0(i, e+1) day[i] = -1;
        FOR0(i, e+1) boom[i] = 0;
        scanf("%d", &source);
        queue<int> q; q.push(source);
        day[source] = 0; boom[0] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            repi(i,graph[u]) {
                if(day[*i] == -1) {
                    day[*i] = day[u] + 1;
                    q.push(*i);
                }
            }
        }
        FOR0(i, e) {
            if(day[i] <= 0) continue;
            boom[day[i]]++;
            if(boom[day[i]] > maxBoom) {
                maxBoom = boom[day[i]];
                boomDay = day[i];
            } else if(boom[day[i]] == maxBoom)
                boomDay = min(boomDay, day[i]);
        }
        if(!graph[source].size()) cout << 0 << endl;
        else cout << maxBoom << ' ' << boomDay << endl;
    }
}