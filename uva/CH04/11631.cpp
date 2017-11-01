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

int Rank[200000 + 10], p[200000 + 10];

void unionFind(int k) {
    FOR0(i, k) Rank[i] = 0;
    FOR0(i, k) p[i] = i;
}
int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
    if(!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if(Rank[x] > Rank[y]) p[y] = x;
        else {
            p[x] = y;
            if(Rank[x] == Rank[y]) Rank[y]++;
        }
    }
}

int n, m, x, y, z;
pair<int, ii> edges[200000 + 10];

int main() {
    while(scanf("%d%d", &m , &n) && m && n) {
        unionFind(m);
        int totalLen = 0, len = 0;
        int edgesUsed = 0;
        FOR0(i, n) {
            scanf("%d%d%d", &x, &y, &z);
            edges[i] = mp(z, mp(x, y));
            totalLen += z;
        }
        sort(edges, edges + n);
        FOR0(i, n) {
            int w = edges[i].first;
            ii edge = edges[i].second;
            if(!isSameSet(edge.first, edge.second)) {
                unionSet(edge.first, edge.second);
                edgesUsed++;
                len += w;
            }
            if(edgesUsed == m-1) break;
        }
        cout << totalLen - len << endl;
    }
}