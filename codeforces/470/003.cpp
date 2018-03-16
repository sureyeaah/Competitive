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
const int N = 3e5 + 5, B = 30;
int n, p=0, a[N], b[N], trie[B*N][2], cnt[B*N][2];
bitset<N> bs;
void binary(int x) {
    FOR0(i, B) bs[B-i-1] = (x & (1 << i)) > 0;
}
void add(int x) {
    binary(x);
    int cur = 0;
    FOR0(i, B) {
        cnt[cur][bs[i]]++;
        if(trie[cur][bs[i]]) cur = trie[cur][bs[i]];
        else cur = trie[cur][bs[i]] = ++p;
    }
}
int best(int x) {
    binary(x);
    int cur = 0, ans = 0;
    FOR0(i, B) {
        if(cnt[cur][bs[i]]) {
            cnt[cur][bs[i]]--;
            cur = trie[cur][bs[i]];
        } else {
            cnt[cur][1^bs[i]]--;
            cur = trie[cur][1^bs[i]];
            ans |= (1 << (B-i-1));
        }
    }
    return ans;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) {cin >> b[i]; add(b[i]);}
    FOR0(i, n) cout << best(a[i]) << " ";
}