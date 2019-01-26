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
const int N = 100;
int n, k, a[N], t;
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int sum = 0;
        FOR0(i, n) {
            cin >> a[i];
            if(a[i] >= k) {
                sum += k;
                a[i] -= k;
            } else {
                sum += a[i];
                a[i] = 0;
            }
        }
        sort(a, a + n); n--;
        int x = 0;
        FOR0(i,n-1) {
            x += a[i];
        }
        if(n) {
            if(a[n-1] > x) x = a[n-1] - x;
            else {
                x = (x + a[n-1]) & 1;
            }
        }
        a[n] -= x;
        sum += a[n];
        cout << sum << endl;
    }
}