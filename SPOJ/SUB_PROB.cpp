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
const int N = 2000 * 1005;
map<char, int> go[N];
int par[N], sz = 1, fail[N], ans[1005] = {};
char pc[N];
vvi cont(N);
void add(string& s, int i ) {
    int cur = 0;
    for(char c : s) {
        auto it = go[cur].find(c);
        if(it == go[cur].end()) {
            par[sz] = cur;
            pc[sz] = c;
            cur = go[cur][c] = sz++;
        } else cur = it->ss;
    }
    cont[cur].pb(i);
}
int nxt(int cur, char c) {
    auto it = go[cur].find(c);
    if(it == go[cur].end()) {
        if(fail[cur] == -1) {
            if(!cur || !par[cur]) return fail[cur] = 0;
            fail[cur] = nxt(par[cur], c);
            for(int x : cont[fail[cur]]) cont[cur].pb(x);
        } else return fail[cur];
    } else return it->ss;
}
int main() {
    SYNC
    string m, s; int n;
    cin >> m >> n;
    memset(fail, -1 ,sizeof fail); 
    par[0] = 0;
    FOR0(i, n) {
        cin >> s;
        add(s, i);
    }
    int cur = 0;
    for(int c : m) {
        cur = nxt(cur, c);
        for(int x : cont[cur]) ans[x] = 1;
    }
    FOR0(i, n) cout << (ans[i] ? 'Y':'N') << newl;
}