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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 12005;
char x[N];
int c[N];
ll p[N]; int ft[N];
set<ll> coord;
unordered_map<ll, int> pos;
void upd(int i, int val) {
    for(;i<N;i+=i&-i) ft[i] += val;
}
int query(int i) {
    int ret = 0;
    for(;i;i-=i&-i) ret += ft[i];
    return ret;
}
int cur = 0;
void solve(vector<ii>& v, set<ll>& d) {
    vector<ii> del;
    memset(ft, 0, sizeof ft);
    while(x[cur] != 'E') {
        if(x[cur] == 'I') {
            int i = 0;
            for(; i < SZ(v); i++) if(v[i].ff >= p[cur]) break;
            v.pb(mp(c[cur], p[cur]));
            FORD(j, i, SZ(v) - 1) {
                v[j].ff++;
                v[j+1] = v[j];
            }
            v[i] = mp(p[cur], c[cur]);
            for(i = 0; i < SZ(del); i++) if(del[i].ff >= p[cur]) break;
            FORD(j, i, SZ(del)) {
                del[j].ff++;
            }
        } else {
            int i = 0;
            for(; i < SZ(v); i++) if(v[i].ff >= p[cur]) break;
            if(i == SZ(v) || v[i].ff != p[cur]) {
                FOR(j, i, SZ(v)) {
                    v[j].ff--;
                }
                int j= 0;
                for(; j < SZ(del); j++) if(del[j].ff >= p[cur]) break;
                del.pb(mp(0,0));
                FOR(k, j, SZ(del) - 1) {
                    del[k].ff--;
                    del[k+1] = del[k]; 
                }
                del[j] = mp(p[cur]-1, p[cur] - i + j);
                d.insert(del[j].ss);
            } else {
                FOR(j, i, SZ(v)-1) {
                    v[j] = v[j+1];
                    v[j].ff--;
                }
                v.pop_back();
                for(i = 0; i < SZ(del); i++) if(del[i].ff >= p[cur]) break;
                FORD(j, i, SZ(del)) {
                    del[j].ff--;
                }
            }
        }
        cur++;
    }
    cur++;
}
int main() {
    SYNC
    coord.insert(1);
    int n = 0; char tmp;
    vector<ii> v1,v2; set<ll> del1, del2;
    while(1) {
        cin >> x[n];
        if(x[n]=='I') {
            cin >> p[n] >> tmp;
            c[n] = 'Z' - tmp;
        }
        else if (x[n] == 'D') cin >> p[n];
        n++;
        if(x[n-1]=='E') break;
        else {
            coord.insert(p[n-1]);
            if(p[n-1] > 1) coord.insert(p[n-1]-1);
            coord.insert(p[n-1]+1);
        }
    }
    while(1) {
        cin >> x[n];
        if(x[n]=='I') {
            cin >> p[n] >> tmp;
            c[n] = 'Z' - tmp;
        }
        else if (x[n] == 'D') cin >> p[n];
        n++;
        if(x[n-1]=='E') break;
        else {
            coord.insert(p[n-1]);
            if(p[n-1] > 1) coord.insert(p[n-1]-1);
            coord.insert(p[n-1]+1);
        }
    }
    int i =0;
    for(ll x : coord) pos[x] = ++i;
    solve(v1, del1); solve(v2, del2);
    // for(auto x : v1) cerr << x.ff << " " << newl;
    // for(auto x : v2) cerr << x.ff << " " << newl;
    // for(auto x : del1) cerr << x << newl;
    cout << !(v1==v2 && del1 == del2);
}