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
const int N = 1e5 + 5; int n, a[N], b[N], x = 0, maxb = 0;
int main() {
    SYNC
    cin >> n;
    map<int,int> m;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) {
        cin >> b[i]; a[i] -= b[i];
        x = __gcd(x, a[i]);
        a[i] += b[i];
        maxb = max(maxb, b[i]);
        m[a[i]] = b[i];
    }
    int xx = -1;
    if(x==0) x = maxb + 1;
    else {
        for(int i = 1, j = sqrt(x) + 2; i < j; i++) {
            if(x % i == 0) {
                if(i > maxb) {xx = i; break;}
                if(x/i > maxb) {xx = x/i;}
            }
        }
        x = xx;
    }
    FOR0(i, n) {
        if(b[i] != m[a[i]]) x = -1;
    }
    cout << x;
}