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
const int N = 1e6 + 8;
int n, w, h, x, y;
int calc(int x, int y) {
    return !x ? y : y == h ? h + x:
    x == w ? 2*h + w - y: 2*h + 2*w - x;
}
vector<pair<int,int>> v;
pair<long double, long double> nxt(int a) {
    a = v[a].ff;
    return a < h ? mp((ld)0, (ld)a + 0.5): a < h + w ? mp((ld)a-h + 0.5, (ld)h):
    a < 2*h + w ? mp((ld)w, (ld)2*h + w - a - 0.5): mp((ld)2*h + 2*w - a - 0.5, (ld)0);
}
int bs[N];

int odd = -1;
void add(int i, int f) {
    odd -= bs[v[i].ss]==1; 
    bs[v[i].ss] += f;
    odd += bs[v[i].ss]==1; 
}
int main() {
    SYNC
    cin >> n >> w >> h;
    FOR0(i, n) {
        FOR0(j, 2) {
            cin >> x >> y;
            v.pb(mp(calc(x, y), i));
        }
    }
    sort(v.begin(), v.end());
    FOR(i, n-1, 2*n) {
        if(odd == -1) {
            odd = 0;
            FOR0(i, n) {
                add(i, 1);
            }
        } else {
            add(i, 1);
            add(i-n,-1);
        }
        if(odd == n) {
            cout << 1 << endl;
            auto p1 = nxt(i);
            auto p2 = nxt(i - n < 0 ? 2*n-1: i-n);
            cout << fixed << setprecision(10) << p1.ff << " " << p1.ss << " " << p2.ff
            << " " << p2.ss;
            return 0;
        }
    }
    cout << 2 << endl;
    cout << fixed << setprecision(10) << 0 << " " << 0.5 << " " << w << " " << (h - 0.5) << endl;
    cout << fixed << setprecision(10) << (w-0.5) << " " << 0 << " " << 0.5 << " " << h;
}