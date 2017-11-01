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
#define N 100005
#define B 21
int t, n, a[N], k, trie[N*22][2], tot;
ll cnt[N*22][2];
bitset<B> bs, kk;
void binary(int x, bitset<B>& bit = bs) {
    FOR0(i, B) {
        bit[B-i-1] = x&1;
        x >>= 1;
    }
}
int add(int x) {
    binary(x);
    int p = 0;
    FOR0(i, B) {
        if(!trie[p][bs[i]])
            trie[p][bs[i]] = ++tot;
        cnt[p][bs[i]]++;
        p = trie[p][bs[i]];
    }
}
ll search(int num) {
    binary(num);
    int p = 0; ll ret = 0;
    FOR0(i, B) {
        if(kk[i]) {
            ret += cnt[p][bs[i]];
        }
        p = trie[p][kk[i]^bs[i]];
        if(!p) break;
    }
    return ret;
}
void test(ll val) {
    ll ans = 0;
    FOR0(i, n) {
        FOR0(j, n) {
            //if(a[i]^a[j])
        }
    }
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> k;
        binary(k, kk);
        ll x = 0;
        memset(trie, 0, sizeof trie);
        memset(cnt, 0, sizeof cnt);
        tot = 0;
        ll ans = 0;
        FOR0(i, n) {
            cin >> a[i];
            add(x);
            x ^= a[i];
            ans += search(x);
            // DEBUG(ans);
        }
        cout << ans << '\n';
    }
}