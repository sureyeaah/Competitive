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
vector<string> p({"xxxxx", "x...x", "....x", "x....", ".....", "..x.."});
vector<string> num(7);
vvi seq({{0,1,1,1,1,1,0}, {2,2,2,2,2,2,2}, {0,2,2,0,3,3,0}, {0,2,2,0,2,2,0}, {1,1,1,0,2,2,2},
    {0,3,3,0,2,2,0}, {0,3,3,0,1,1,0}, {0,2,2,2,2,2,2}, {0,1,1,0,1,1,0}, {0,1,1,0,2,2,0}});
unordered_map<string, int> m;
int getNum(int st, int nd) {
    int ret = 0;
    for(int i = st; i < nd; i+=6) {
        vi vec;
        FOR0(j, 7) vec.pb(m[num[j].substr(i, 5)]);
        FOR(k,0,10) if(vec==seq[k]) ret = ret*10 + k;
    }
    return ret;
}
int main() {
    SYNC
    FOR0(i, 7) {
        cin >> num[i];
    }
    FOR0(i, SZ(p)) m[p[i]]=i;
    int cur = 0;
    for(int i = 0; i < (int)num[0].length(); i+=6) {
        if(num[0].substr(i, 5) == p[4]) cur = i;
    }
    int z = getNum(0, cur);
    // DEBUG(z);
    z += getNum(cur + 6, num[0].length());
    vi vec;
    while(z) {
        vec.pb(z%10);
        z /= 10;
    }
    FOR0(i, 7) {
        FORD(j, 0, SZ(vec)) {
            cout << p[seq[vec[j]][i]];
            cout << (!j ? newl: '.'); 
        }
    }
}