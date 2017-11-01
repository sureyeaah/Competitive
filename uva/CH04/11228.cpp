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
vector<iii> edges;
int n, r, r2, x, y, t, coords[2010][2], dist[2010][2010];

class unionFind {
public:
    int p[2010], Rank[2010];
    void clear(int k) {
        FOR0(i, k) p[i] = i;
        FOR0(i, k) Rank[i] = 0;
    }
    int findSet(int i) {
        return (i == p[i]) ? i : (p[i] = findSet(p[i]));
    }
    int sameSet(int i, int j) {
        return (findSet(i) == findSet(j));
    }
    void unionSet(int i, int j) {
        int x = findSet(i), y = findSet(j);
        if(x != y) {
            if(Rank[x] > Rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(Rank[x] == Rank[y]) Rank[y]++;
            }
        }
    }
};

int main() {
    unionFind uf, suf, ruf;
    map<int, int> stateIndex;
    FOR0(i, 2005) dist[i][i] = 0;
    scanf("%d", &t);
    FOR(caseNumber, 1, t+1) {
        scanf("%d%d", &n, &r);
        r2 = r*r;
        FOR0(i, n)
            scanf("%d%d", &coords[i][0], &coords[i][1]);
        uf.clear(n);
        suf.clear(n);
        stateIndex.clear();
        edges.clear();
        FOR0(i, n) {
            FOR0(j, i) {
                int dist2 = pow(coords[i][0] - coords[j][0],2)  + pow(coords[i][1] - coords[j][1],2);
                edges.pb(mp(dist2,mp(i, j)));
                if(dist2 <= r2) suf.unionSet(i, j);
            }
        }
        sort(edges.begin(), edges.end());
        int numStates = 0;
        double roadLen = 0, railwayLen = 0;
        FOR0(i, n) if(suf.findSet(i) == i) stateIndex[i] = numStates++;
        ruf.clear(numStates);
        FOR0(i, edges.size()) {
            int dist2 = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
            if(suf.sameSet(u,v)) {
                if(!uf.sameSet(u, v)) {
                    uf.unionSet(u, v);
                    roadLen += sqrt((double)dist2);
                }
            } else {
                int usi = stateIndex[suf.findSet(u)], vsi = stateIndex[suf.findSet(v)];
                if(!ruf.sameSet(usi,vsi)) {
                    ruf.unionSet(usi, vsi);
                    railwayLen += sqrt((double)dist2);
                }
            }
        }
        printf("Case #%d: %d %.0f %.0f\n", caseNumber,numStates, roadLen, railwayLen);
    }
}