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

int n, visited = 0, covered[35][4] = {false}, u, v, coords[35][2], border[4] = {};
int dir_x = {1,0,-1,0}, dir_y = {0,-1,0,1};
bool possible = true;
void build (int u) {
    visited |= 1 << u;
    repi(i, tree[u]) {
        int v = *i;
        if(!(visited & (1 << v))) {
            FOR0(dir, 4) {
                if(!covered[u][i]) {
                    int x = dir_x[dir], y = dir_y[dir];
                    
                }
            }
        }
    }
}

int main() {
    
    cin >> n;
    vvi tree(n+1);
    FOR0(i, n-1) {
        scanf("%d%d",&u, &v);
        tree[u-1].pb(v-1);
        tree[v-1].pb(u-1);
    }
    coords[0][0] = coords[0][1] = 0;
    FOR0(i, n) {
        if(tree[i].size() > 4) possible = false;
    }
    if(possible) {
        build(0);
    }
}