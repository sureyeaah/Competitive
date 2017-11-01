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
int t, n, a[N], trie[N*32][2], tot;
bitset<32> bs;
void binary(int x) {
    bs.reset();
    FOR0(i, 32) {
        bs[31 - i] = x & 1;
        x >>= 1;
    }
}
void add(int x) {
    binary(x);
    int p = 0;
    FOR0(i, 32) {
        if(!trie[p][bs[i]]) trie[p][bs[i]] = ++tot;
        p = trie[p][bs[i]];
    }
}
int search(int x) {
    binary(x);
    int p = 0;
    FOR0(i, 32) {
        if(trie[p][!bs[i]]) {
            p = trie[p][!bs[i]];
            if(!bs[i]) x ^= 1 << (31 - i);
        } else {
            p = trie[p][bs[i]];
            if(bs[i]) x ^= 1 << (31 - i);
        }
    }
    return x;
}
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n;
        memset(trie, 0, sizeof trie);
        tot = 0;
        FOR0(i, n) cin >> a[i];
        FOR0(i, n-1) a[i+1] ^= a[i];
        add(0);
        FOR0(i, n) add(a[i]);
        int ans = 0;
        FOR0(i, n) ans = max(ans, search(a[i]));
        cout << ans << '\n';
    }
}