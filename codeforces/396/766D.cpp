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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 100005
int t, n, m, q, par[maxn], ant[maxn], rel;
map<string, int> words; int cnt = 0;
string s;
int findSet(int u) {
    return par[u] == u ? u : (par[u] = findSet(par[u]));
}
bool sameSet(int u, int v) {
    return findSet(u)==findSet(v);
}
bool unite(int u, int v, int antu, int antv) {
    if(u != v) {
        if(antu == v || antv == u) return false;
        par[u] = v;
        if(antu != - 1 || antv != -1) {
            int z = max(antu, antv), zz = antu + antv - z;
            ant[v] = z;
            ant[z] = v;
            if(zz > -1) par[zz] = z;
        }
    }
    return true;
}
bool unite2(int u, int v, int antu, int antv) {
    if(sameSet(u, v)) return false;
    if(antv == -1 && antu == -1) {
        ant[u] = v; ant[v] = u;
        return true;
    } else if(antv == -1) {
        swap(u, v);
        swap(antu, antv);
    }
    return unite(u,antv,antu,v);
}

int main() {
    SYNC;
    cin >> n >> m >> q;
    FOR0(i, n) {
        cin >> s;
        words[s] = cnt++;
        ant[i] = -1;
        par[i] = i;
    }
    while(m--) {
        cin >> rel >> s; int u = findSet(words[s]);
        cin >> s; int v = findSet(words[s]);
        int antu = ant[u] == -1 ? -1 : findSet(ant[u]);
        int antv = ant[v] == -1 ? -1 : findSet(ant[v]);
        if(rel == 1) cout << (unite(u,v,antu,antv) ? "YES": "NO") << '\n';
        else cout << (unite2(u,v,antu,antv) ? "YES": "NO") << '\n';
    }
    while(q--) {
        cin >> s; int u = findSet(words[s]);
        cin >> s; int v = findSet(words[s]);
        if(sameSet(u, v)) cout << 1 << '\n';
        else if((ant[u] == -1 ? -1 : findSet(ant[u])) == v || (ant[v] == -1 ? -1 : findSet(ant[v])) == u) cout << 2 << '\n';
        else cout << 3 << '\n';
    }
}