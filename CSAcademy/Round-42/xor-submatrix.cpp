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
vi odd[2];
#define N 100
int solve(int a[], int n, int ind) {
    int ans = 0;
    int dp[1001] = {};
    FOR(i, 1, n+1) dp[i] = dp[i-1]^a[i-1];
    FOR(i, 1, n+1) {
        FOR(j, 1, i + 1) {
            if((i-j+1)&1) {
                odd[ind].pb(dp[i]^dp[j-1]);
            } else {
                ans = max(dp[i]^dp[j-1], ans);
            }
        }
    }
    return ans;
}
int trie[N*N*30][2] = {};
int tot = 0;

void add(int x) {
    bitset<29> bs;
    FOR0 (i, 29) {
        bs[28 - i] = x&1;
        x >>= 1;
    }
    int ptr = 0;
    FOR0(i, 29) {
        if(trie[ptr][bs[i]])
            ptr = trie[ptr][bs[i]];
        else ptr = trie[ptr][bs[i]] = ++tot;
    }
}

int search(int x) {
    bitset<29> bs;
    int ret = x;
    FOR0 (i, 29) {
        bs[28 - i] = x&1;
        x >>= 1;
    }
    int ptr = 0;
    FOR0(i, 29) {
        if(trie[ptr][!bs[i]]) {
            if(!bs[i]) ret ^= 1 << (28 - i);
            ptr = trie[ptr][!bs[i]];
        }
        else {
            ptr = trie[ptr][bs[i]];
            if(bs[i]) ret ^= 1 << (28 - i);
        }
    }
    return ret;
}

int main() {
    SYNC
    int n, m, u[1001], v[1001];
    cin >> n >> m;
    FOR0(i, n) cin >> u[i];
    FOR0(i, m) cin >> v[i];
    int ans = max(solve(u, n, 0), solve(v, m, 1));
    for(int x : odd[0]) {
        add(x);
    }
    for(int x : odd[1]) {
        ans = max(ans, search(x));
    }
    cout << ans;
}