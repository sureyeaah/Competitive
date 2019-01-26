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
int n; 
const int A = 32000;
int main() {
    SYNC
    cin >> n;
    V<P<int, int>> f;
    for(int i = 2; i < A; i++) {
        int j = 0;
        while((n % i) == 0) {
            j++; n/= i;
        }
        if(j) {
            f.push_back(make_pair(i, j));
        }
    }
    if(n > 1) f.push_back(make_pair(n, 1)); 
    if(f.size() == 1) {cout << "NO"; return 0;}
    int p1 = f[0].first, p2 = f[1].first;
    f[0].second--;
    f[1].second--;
    V<P<int, int>> sol;
    FOR(i, 1, p1) {
        int r = p1 * p2 - 1 - i * p2, j = r/p1;
        if(r % p1 == 0 && j < p2) {
            sol.push_back(make_pair(i, p1));
            sol.push_back(make_pair(j, p2));
            break;
        }
    }
    for(auto p : f) {
        FOR0(i, p.second) {
            for(auto &cur : sol)
                cur.second *= p.first;
            sol.push_back(make_pair(p.first-1, p.first));
        }
    }
    cout << "YES" << endl;
    cout << sol.size() << endl;
    for(auto cur: sol) cout << cur.first << " " << cur.second << endl;
}