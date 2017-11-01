#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define mod (7 + (int)1e9)
#define N 100005

ll solve(ll arr[], int n) {
    ll ret = 0;
    FOR0(i, n) {
        ret += (arr[i] * (n-i-1)) % mod;
        ret %= mod;
    }
    FOR0(i, n) {
        ret -= (arr[i] * i) % mod;
        ret %= mod;
    }
    return (ret + mod) % mod;
}
int main() {
    SYNC
    int n, m;
    ll x[N], y[N];
    cin >> n >> m;
    FOR0(i, n) cin >> x[i];
    FOR0(i, m) cin >> y[i];
    sort(x, x + n, greater<ll> ());
    sort(y, y + m, greater<ll> ());
    cout << ((solve(x, n)*solve(y,m)) % mod + mod) % mod;
}