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
ll add(ll x, ll y) {return (x+y) % mod;}
ll mul(ll x, ll y) {return (x*y) % mod;}
ll modexp(ll a, int b=mod-2) {
  ll ans = 1;
  for(;b;b>>=1) {
    if(b&1) ans = mul(ans, a);
    a = mul(a, a);
  }
  return ans;
} 
int main() {
  SYNC
  int t, n; cin >> t;
  while(t--) {cin >> n;  int i = n;
  ll ans = add(
    add(modexp(mul(i, mul(i+1, modexp(2))), 2), 
      mul(i, mul(i+1, mul(2*i+1, modexp(2))))), mul(i, i+1));
  ans= mul(ans, modexp(6));
  cout << add(mod,ans) << endl; }
}