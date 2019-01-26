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
const ld EPS = 1e-9, PI = acosl(-1.0);
int t, n;
ll l, r; 
unsigned long long x, b, y, z, b1, b2;
ll A(unsigned long long b) {
    return (b % ((unsigned long long)(r - l + 1))) + l;
}
vector<ll> s;
void ins(ll a) {
    if(a >= 0) return;
    while(!s.empty() && s.back() < a) s.pop_back();
    s.push_back(a);
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
        ll a1 = A(b1), a2 = A(b2), amin = min(a1, a2);
        ll ans = a1 < a2 ? a1 * a2: 0;
        int found = a1 < a2;
        ins(a1); ins(a2);
        FOR(i, 3, n + 1) {
            b = (b1 * x) & ((1ULL << 32) - 1);
            b = (b + ((b2 * y) & ((1ULL << 32) - 1))) & ((1ULL << 32) - 1);
            b = (b + z)& ((1ULL << 32) - 1);
            a2 = A(b);
            if(a2 < 0) {
                ll l = 0;
                while(!s.empty() && s.back() < a2) {l = s.back(); s.pop_back();}
                if(l < 0) ans = found ? min(ans, l*a2): l*a2, found = 1;
                s.push_back(a2);
            }
            if(a2 > amin) ans = found ? min(ans, amin * a2): amin * a2, found = 1;
            amin = min(a2, amin);
            b1 = b2; b2 = b;
        }
        if(!found) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
        s.clear();
    }
}