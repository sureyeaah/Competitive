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
const int N = 1e6 + 5;
int n, k, a[N];
int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    int x = *min_element(a, a + n);
    if(!k) {
        if(x != *max_element(a, a+n)) {cout << -1; return 0;}
        cout << n * 1LL * x << endl; return 0;
    }
    FOR(i, 1, n) {
        if((a[i] - x) % k) {cout << -1; return 0;}
    }
    FOR(i, 1, k + 1) {
        if((x-i) % k == 0) {
            cout << n * 1LL * i << endl; return 0;
        }
    }

}