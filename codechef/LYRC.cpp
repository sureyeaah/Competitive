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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 500*5005;
unordered_map<char, int> nxt[N], go[N];
int par[N], sz = 1, link[N]={};
char parc[N];
int done[N];
int fin[505]={},vis[N]={};
void add(string& s, int i) {
    int cur = 1;
    for(char c : s) {
        if(!nxt[cur][c]) {
            sz++;
            parc[sz]=c,par[sz]=cur,nxt[cur][c]=sz,cur=sz;
        }
        else cur=nxt[cur][c];
    }
    fin[i]=cur;
    // occ[cur]++;
    // occur[cur].pb(i);
}
int GO(int p, char c);
int getlink(int p) {
    if(!link[p]) {
        if(p==1 || par[p]==1) link[p]=1;
        else {
            link[p]=GO(getlink(par[p]),parc[p]);
            // occ[p] += occ[link[p]];
            // for(int x : occur[link[p]]) occur[p].insert(x);
        }
        done[link[p]]++;
    }
    return link[p];
}
int GO(int p, char c) {
    auto it = nxt[p].find(c);
    if(it == nxt[p].end()) {
        auto it = go[p].find(c);
        if (it==go[p].end())
            return (go[p][c]= p==1 ? 1: GO(getlink(p),c));
        else return it->ss;
    } else return it->ss;
}
int main() {
    SYNC
    string s; int n, m;
    cin >> n;
    FOR0(i, n) {
        cin >> s;
        add(s, i);
    }
    cin >> m;
    while(m--) {
        cin >> s;
        int cur = 1;
        for(char c : s) {
            cur = GO(cur, c);
            vis[cur]++;
        }
    }
    FOR(i, 1, sz + 1) getlink(i);
    queue<int> q;
    FOR(i, 1, sz + 1) if(0==done[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        done[link[u]]--;
        if(0==done[link[u]]) q.push(link[u]);
        vis[link[u]]+=vis[u];
    }
    FOR0(i, n) cout << vis[fin[i]] << newl;
}