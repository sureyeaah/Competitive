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
const int inf = 1e9, mod = 1e9 + 9;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 5e6;
int p[N], f[N], q[N];
ll x[N];
int main() {
    SYNC
    int n; string s; cin >> n >> s;
    string T = "#";
    for(char c : s) T += c, T += '#';
    int m = T.length();
    int C = 0, R = -1, rad; 
    for (int i = 0; i < m; ++i) {
        if (i <= R) {
            rad = min(p[2*C-i], R-i); 
        } else {
            rad = 0; 
        }
        // Try to extend
        while (i+rad < m && i-rad >= 0 && T[i-rad] == T[i+rad]) {
            rad++; 
        }
        p[i] = rad;
        if (i + rad - 1 > R) {
            C = i; 
            R = i + rad - 1; 
        }
    }
    FOR0(i, m) {
        f[i + p[i]]--;
        f[i]++;
    }
    FOR0(i, m) f[i+1] += f[i];
    
    multiset<int> ms;
    ll sum = 0;
    FOR0(i, n) {
        q[i] = (p[i<<1])/2;
    }
    FOR0(i, n) {
        sum -= ms.size();
        ms.insert(q[i] + i);
        sum += q[i];
        while(!ms.empty() && ((*ms.begin()) - i <= 0)) {
            ms.erase(ms.begin());
        }
        x[i*2+1] += sum;
    }
    ms.clear(); sum = 0;
    FOR0(i, n) {
        q[i] = (p[i<<1|1]+1)/2;
    }
    FOR0(i, n) {
        sum -= ms.size();
        ms.insert(q[i] + i);
        sum += q[i];
        while(!ms.empty() && ((*ms.begin()) <= i)) {
            ms.erase(ms.begin());
        }
        x[i*2+1] += sum;
    }
    ms.clear(); sum = 0;



    FOR0(i, m/2) swap(p[i], p[m-i-1]);
    FOR0(i, n) {
        q[i] = (p[i<<1])/2;
    }
    FOR0(i, n) {
        sum -= ms.size();
        ms.insert(q[i] + i);
        sum += q[i];
        while(!ms.empty() && ((*ms.begin()) - i <= 0)) {
            ms.erase(ms.begin());
        }
        x[m-i*2-2] += sum;
    }
    ms.clear(); sum = 0;
    FOR0(i, n) {
        q[i] = (p[i<<1|1]+1)/2;
    }
    FOR0(i, n) {
        sum -= ms.size();
        ms.insert(q[i] + i);
        sum += q[i];
        while(!ms.empty() && ((*ms.begin()) <= i)) {
            ms.erase(ms.begin());
        }
        x[m-i*2-2] += sum;
    }
    ms.clear(); sum = 0;
    ll ans = 0;
    FOR0(i, m/2) swap(p[i], p[m-i-1]);
    FOR0(i, m) {
        if((i & 1) == 0) continue;
        x[i] -= (p[i] + 1) / 2;
        x[i] %= mod;
        ans += f[i] * 1LL * (x[i] - f[i]);
        ans %= mod;
        ans += (f[i] * 1LL * (f[i] - 1)) / 2;
        ans %= mod;
    }
    if(ans < 0) ans += mod;
    cout << ans;
}