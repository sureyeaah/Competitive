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
int q, t;
ll k, x;
ll shift[100] = {}, shift2[100] = {};
void modulo(ll&x, int i) {
    x &= (1LL << i) - 1;
}
void mv(ll&x, ll k, int lvl) {
    modulo(k, lvl);
    if(k < 0) k += 1LL << lvl;
    x += k;
    if(x >= (1LL << (lvl+1))) x -= 1LL << lvl;
    else if(x < (1LL << (lvl))) x += 1LL << lvl;
}
int main() {
    SYNC
    cin >> q;
    while(q--) {
        cin >> t;
        if(t==3) {
            cin >> x;
            int lvl = 0;
            for(int i = 0; i <= 62; i++) if(x & (1LL<<i)) lvl = i;
            FORD(i, 0, lvl) {
                cout << x << " ";
                mv(x, shift[i+1] + shift2[i+1], i+1);
                x >>= 1;
                mv(x, -shift[i], i);
            }
            cout << x << endl;

        } else {
            cin >> x >> k;
            int lvl = 0;
            for(int i = 0; i <= 62; i++) if(x & (1LL<<i)) lvl = i;
            if(t==1) {
                shift[lvl] += k;
                modulo(shift[lvl], lvl);
                if(shift[lvl]<0) shift[lvl]+= 1LL << lvl;
                
            } else {
                shift2[lvl] += k;
                modulo(shift2[lvl], lvl);
                if(shift2[lvl]<0) shift2[lvl]+= 1LL << lvl;
            }
        }
    }
}