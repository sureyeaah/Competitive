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
long double e[N];
string s; int n;
long double f[N];
int main() {
    freopen("foreign.in", "r", stdin);
    freopen("foreign.out", "w", stdout);
    cin >> s; n = s.length();
    e[0] = 0; f[0] = 0;
    FOR(i, 1, n + 1) {
        f[i] = f[i-1] + (s[n-i] == 'W') * i;
    }
    FOR(i, 1, n + 1) {
        if(s[n-i] == 'C') {
            e[i] = e[i-1]/i + f[i] / ((ld)i);
        } else e[i] = e[i-1]/i + (i + 1) / 2.0 - f[i] / ((ld)i);
        e[i] += e[i-1];
    }
    cout << fixed << setprecision(10) << e[n] - e[n-1];
}