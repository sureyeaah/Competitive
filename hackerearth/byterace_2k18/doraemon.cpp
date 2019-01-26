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
const int N = 2000, B = 30;
int trie[N*(B+1)][2] = {};
int tot = 0;

void add(ll x) {
    bitset<B> bs;
    FOR0 (i, B) {
        bs[B-1-i] = x&1;
        x >>= 1;
    }
    int ptr = 0;
    FOR0(i, B) {
        if(trie[ptr][bs[i]])
            ptr = trie[ptr][bs[i]];
        else ptr = trie[ptr][bs[i]] = ++tot;
    }
}

int search(int x) {
    bitset<B> bs;
    ll ret = x;
    FOR0 (i, B) {
        bs[B - 1 - i] = x&1;
        x >>= 1;
    }
    int ptr = 0;
    FOR0(i, B) {
        if(trie[ptr][!bs[i]]) {
            if(!bs[i]) ret ^= 1LL << (B-1 - i);
            ptr = trie[ptr][!bs[i]];
        }
        else {
            ptr = trie[ptr][bs[i]];
            if(bs[i]) ret ^= 1LL << (B-1 - i);
        }
    }
    return ret;
}
int n, a[N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> a[i];
    int ans = 0;
    add(0);
    FOR0(i, n) add(a[i]);
    FOR(i, 0, n) {
        FOR(j, i, n) {
            ans = max(ans, search(a[i]^a[j]));
        }
    }
    cout << ans;
}