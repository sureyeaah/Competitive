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
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int nxta[4][4], nxtb[4][4], vis[50] = {};
ll k;
vi st;
void dfs(int a, int b) {
    int u = a*4 + b;
    st.pb(u);
    if(vis[u]) {
        return;
    }
    vis[u] = 1;
    dfs(nxta[a][b], nxtb[a][b]);
}
int main() {
    SYNC
    int a, b;
    int defeats[4] = {0,2,3,1};
    cin >> k >> a >> b;
    FOR0(i, 3) FOR0(j, 3) cin >> nxta[i+1][j+1];
    FOR0(i, 3) FOR0(j, 3) cin >> nxtb[i+1][j+1];
    dfs(a, b);
    int i = SZ(st)-2;
    while(st[i] != st[SZ(st)-1]) {
        i--;
        continue;
    }
    ll ansa = 0, ansb = 0;
    int rest = i, cycle = SZ(st) - 1 - i;
    i = 0;
    while(k && i < rest) {
        int a = st[i]/4, b = st[i] % 4;
        if(a == defeats[b]) ansa++;
        else if(b == defeats[a]) ansb++;
        k--;
        i++;
    }
    if(k) {
        FOR(i, rest, rest + cycle) {
            int a = st[i]/4, b = st[i] % 4;
            if(a == defeats[b]) ansa+= (k/cycle) + (k%cycle > i-rest);
            else if(b == defeats[a]) ansb+= (k/cycle) + (k%cycle > i-rest);
        }
    }
    cout << ansa << " " << ansb << endl;
}