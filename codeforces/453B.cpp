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
const int N = 31, X = 101;
int n, a[X], b[X], f[2*N];
vector<int> primes;
P<int, int> dp[X][1 << 17];
void sieve() {
    FOR(i, 2, 61) {
        for(int x : primes) {
            if(i % x == 0)
                f[i] |= f[x];
        }
        if(!f[i]) {
            f[i] |= 1 << ((int)primes.size());
            primes.push_back(i);
        }
    }
}
int main() {
    SYNC;
    sieve();
    cin >> n;
    FOR0(i, n) cin >> a[i];
    int m = primes.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << m); j++) {
            dp[i+1][j] = {inf, 1};
            for(int k = 1; k < 2*a[i]; k++) {
                if((j & f[k]) == f[k]) {
                    dp[i+1][j] = min(dp[i+1][j],
                            make_pair(dp[i][j-f[k]].first + abs(k - a[i]), k));
                }
            }
        }
    }
    cerr << dp[2][3].first << endl;
    int i = n, j = 1 << m;
    j--;
    while(i) {
        b[i-1] = dp[i][j].second;
        j -= f[b[i-1]];
        i--;
    }
    FOR0(i, n) cout << b[i] << " " ;
}
