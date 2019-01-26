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
int main() {
    SYNC
    cin >> n;
    V<ll> a(n), b(n/2);
    FOR0(i, n/2) cin >> b[i];
    a[0] = 0, a[n-1] = b[0];
    FOR(i, 1, n/2) {
        int j = n - i - 1;
        if(b[i] - a[i-1] <= a[j+1]) a[i] = a[i-1];
        else a[i] = b[i] - a[j+1];
        a[j] = b[i] - a[i];
    }
    FOR0(i, n) cout << a[i] << " ";
}