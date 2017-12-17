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
vector<vector<int> > g;
vector<vector<int> > rg;
set<pair<int,int> > ans;
vector<pair<int,int> > e;
vector<bool> v;
void dfs(int u){
    v[u]=1;
    for(auto i:g[u])    if(!v[i]){
        ans.insert({u,i});
        dfs(i);
    }
}
void rdfs(int u){
    v[u]=1;
    for(auto i:rg[u])    if(!v[i]){
        ans.insert({i,u});
        rdfs(i);
    }
}
int main() {
    SYNC
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;    
        g.clear();
        rg.clear();
        e.clear();
        ans.clear();
        g.resize(n+1);
        rg.resize(n+1);
        v.assign(n+1,false);
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            e.pb({u,v});
            g[u].pb(v);
            rg[v].pb(u);
        }
        dfs(1);
        v.assign(n+1,false);
        rdfs(1);
        for(auto i:e){
            if((int)ans.size() >= 2*n && (ans.find(i)==ans.end())){
                cout<<i.first<<" "<<i.second<<"\n";
            }
            else
                ans.insert(i);
        }
    }
}