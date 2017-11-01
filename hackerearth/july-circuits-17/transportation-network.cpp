#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
class dsu {
public:
    vvi child;
    vi par;
    set<int> s;
    dsu(int n) {
        par.resize(n + 2);
        child.resize(n + 2);
        FOR0(i, n + 1) par[i] = i;
        FOR0(i, n + 1) child[i].pb(i);
    }
    void unite(int u, int v) {
        u = par[u]; v = par[v];
        if(u != v) {
            int x = SZ(child[u]), y = SZ(child[v]);
            if(x >= y) swap(u, v);
            for(int c : child[u]) {
                par[c] = v;
                s.insert(c);
                child[v].pb(c);
            }
            child[u].clear();
        }
    }
};

int main() {
    SYNC
    int n, q, type, u, v;
    cin >> n >> q;
    dsu g[2] {n, n};
    while(q--) {
        cin >> type >> u >> v;
        type--;
        g[type].unite(u, v);
        for(type = 0; type < 2; type++) {
            set<int> & cur = g[type].s;
            for(int x : cur) {
                int p1 = g[type].par[x], p2 = g[!type].par[x];
                if(g[type].par[p2] == p1 && p2 == g[!type].par[p1]) {
                    cur.erase(x);
                    if(g[!type].s.find(x) != g[!type].s.end())
                        g[!type].s.erase(x);
                } else {
                    type = 2;
                    break;
                }
            }
        }
        cout << (g[0].s.empty() && g[1].s.empty() ? "YES" : "NO") << '\n';
    }
}