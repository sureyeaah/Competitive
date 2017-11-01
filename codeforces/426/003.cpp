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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll cb(ll x) {
    ll l = 0, r = 1e6 + 5;
    ll ret = 1e9 + 10;
    while (l <= r) {
        ll mid = (l + r ) >> 1;
        if(mid*mid*mid >= x) {
            ret = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return ret;
}
int main() {
    SYNC
    int n;
    ll a, b;
    cin >> n;
    while(n--) {
        cin >> a >> b;
        int ans = 0;
        if(1){
            ll g = gcd(a, b);
            ll aa = a/g, bb = b/g;
            ll x = aa * bb * (aa + bb);
            if((a + b) % x == 0) {
                x = (a + b) / x;
                ll y = cb(x);
                if(y*y*y == x) {
                    ll xx = aa*y;
                    ll yy = bb*y;
                    if(a == xx*xx*yy && b == xx*yy*yy) ans = 1;
                }
            }
        }
        cout << (ans ? "Yes": "No") << '\n';
    }
}