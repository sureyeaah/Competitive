#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1 << 23;
const int N = 2e6 + 5;

vector<int> v[N];

ll modInv(ll a, ll mod = mod){
    ll x0 = 0, x1 = 1, r0 = mod, r1 = a;
    while(r1){
        ll q = r0 / r1;
        x0 -= q * x1; swap(x0, x1);
        r0 -= q * r1; swap(r0, r1);
    }
    return x0 < 0 ? x0 + mod : x0;
}
ll modexp(ll a, ll b) {
    ll ans = 1;
    for(;b>0;b>>=1) {
        if(b&1) 
            ans = ans*a % mod;
        a=a*a%mod;
    }
    return ans;
}

int fac[N], ifac[N], inv[N];

void prencr(){
    fac[0] = ifac[0] = inv[1] = 1;
    for(int i = 2; i < N; ++i)
        inv[i] = mod - 1LL * (mod / i) * inv[mod % i] % mod;
    for(int i = 1; i < N; ++i){
        fac[i] = 1LL * i * fac[i - 1] % mod;
        ifac[i] = 1LL * inv[i] * ifac[i - 1] % mod;
    }
}

int C(int n, int r){
    return (r >= 0 && n >= r) ? (1LL * fac[n] * ifac[n - r] % mod * ifac[r] % mod) : 0;
}
int S(int n) {
    ll ans = 1;
    for(int r = 2; r <= n; r++) {
        ans += (C(n,r) * 1LL * (r-1) % mod ) * 1LL* fac[(n-r+1)] % mod;
        ans %= mod;
    }
    return ans;
}
int main(){
    prencr();
    int n;
    cin >> n;

    cout << S(n);
}
