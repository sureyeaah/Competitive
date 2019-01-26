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
int n, a[N], fac[N];
V<V<int>> ind(N);
bitset<N> bs;
void sieve() {
    bs.set(); bs[0] = bs[1] = 0;
    for(int i = 2; i < N; i++) {
        if(!bs[i]) continue;
        for(int j = i; j < N; j+=i) {
            if(j != i) bs[j] = 0;
            if(!fac[j]) fac[j] = i;
        }
    }
}
ll c2(ll x) {return (x*(x-1)) / 2;}
int main() {
    SYNC
    sieve();
    cin >> n;
    FOR0(i, N) {ind[i].push_back(0);}
    FOR0(i, n) {
        cin >> a[i];
        while(a[i] > 1) {
            // cerr << fac[a[i]] << " ";
            if(ind[fac[a[i]]].back() != i+1) {
                ind[fac[a[i]]].push_back(i+1);
            }
            a[i] /= fac[a[i]];
        }
        // cerr << endl;
    }
    ll ans = 0;
    FOR0(i, N) {
        ind[i].push_back(n+1);
        ans += c2(n);
        FOR0(j, ind[i].size()-1) {
            ans -= c2(ind[i][j+1] - ind[i][j] - 1);
        }
        ans += (ind[i].size() - 2);
        // ans += (cnt[i] *1LL* (n - cnt[i])) + ((cnt[i] *1LL* (cnt[i] - 1))/2);
    }
    cout << ans;
}