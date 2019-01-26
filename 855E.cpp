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
string base(ll x, ll b) {
    string ret = "";
    while(x) {
        ret += '0' + (x % b);
        x /= b;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
ll val(int len) {
        
}
ll query(ll x, int b) {
    if(!x) return 0;
    string s = base(x,b);
    if(s.length() & 1) return val()
}
int main() {
    SYNC
    int q, b; ll l, r;
    cin >> q;
    while(q--) {
        cin >> b >> l >> r;
        cout << query(r, b) - query(l-1, b) << '\n';
    }
}