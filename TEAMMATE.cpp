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
const int N = 1e5 + 5;
V<int> prod(N);
int mul(int a, int b) {return a * 1LL * b % mod;}
int f(int a) {a >>= 1; return prod[a];}


int main() {
    SYNC
    prod[0] = 1;
    for(int i = 1; i < N; i ++) {
        prod[i] = mul(prod[i-1], 2*i - 1);
    }
    int t, n, s;
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, int> m;
        while(n--) {
            cin >> s;
            m[s]++;
        }
        n = (int)m.size();
        V<int> v;
        for(auto x : m) {
            v.push_back(x.second);
        }
        V<V<int>> dp(n, V<int>(2));
        for(int i = 0; i < n; i++) {
            if(!i) {
                dp[i][0] = v[i] & 1 ? 0 : f(v[i]);
                dp[i][1] = v[i] & 1 ? mul(f(v[i]-1), v[i]): 0;
            } else {
                dp[i][0] = v[i] & 1 ? mul(mul(v[i], dp[i-1][1]), f(v[i] - 1)):
                    mul(f(v[i]), dp[i-1][0]);
                dp[i][1] = v[i] & 1 ? mul(v[i], mul(f(v[i] - 1), dp[i-1][0])):
                    mul(v[i], mul(v[i] - 1, mul(dp[i-1][1], f(v[i] - 2)))); 
            }
        }
        cout << dp[n-1][0] << endl;
    }
}