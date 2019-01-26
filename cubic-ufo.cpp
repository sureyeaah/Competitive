// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-12, PI = acosl(-1.0);
int t; long double a;
void out(ld x, ld y, ld z) {
    cout << fixed << setprecision(10) << x << " " << y << " " << z << endl;
}
int main() {
    SYNC
    ld mx = sqrtl(2);
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cout << printCase() << endl;
        cin >> a;
        if(a - mx > EPS) {
            ld theta = PI/4 - acosl(min((ld)1.0, a/2));
            ld c = cosl(theta), s = sinl(theta), x = 0.5/mx;
            out(0, -0.5*s, 0.5 * c);
            out(x, x*c, x*s);
            out(-x, x*c, x*s);
        } else {
            // ld theta = PI/4 - acosl(min((ld)1.0, a/mx));
            ld s = (a - sqrtl(2-a*a)) / 2, c = a - s;
            out(0, 0, 0.5);
            out(0.5*c, 0.5*s, 0);
            out(-0.5*s, 0.5*c, 0);
        }
    }
}