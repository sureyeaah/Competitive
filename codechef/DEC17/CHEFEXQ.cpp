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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1e5 + 5, S = 400;
int n, q, a[N], type, ind, x, val[S] = {}, sq, blocks;
unordered_map<int, int> cnt[S];
int update(int tot, int block) {
    int cur = 0;
    val[block] ^= tot;
    cnt[block].clear();
    FOR(i, block * sq, min(block*sq + sq, n)) {
        cur ^= a[i];
        cnt[block][cur]++;
    }
    return cur ^ val[block];
}
void build() {
    int cur = 0;
    for(int i = 0; i < blocks; i++) {
        cnt[i].reserve(512);
        cnt[i].max_load_factor(0.25);
        cur = update(cur, i);
    }
}
int query() {
    int block = ind/sq, ans = 0, cur = val[block];
    for(int i = 0; i < block; i++) {
        auto it = cnt[i].find(val[i] ^ x);
        if(it != cnt[i].end()) ans += it->ss;
    }
    for(int i = sq * block; i <= ind; i++) {
        cur ^= a[i];
        ans += (cur == x);
    }
    return ans;
}
int main() {
    SYNC
    cin >> n >> q;
    sq = pow((double)n, 0.5); blocks = (n-1)/sq + 1;
    FOR0(i, n) cin >> a[i];
    build();
    while(q--) {
        cin >> type >> ind >> x;
        ind--;
        if(type == 1) {
            swap(x, a[ind]);
            int cur = ind / sq;
            update(0, cur);
            FOR(i, cur + 1, blocks) {
                val[i] ^= x^a[ind];
            }
        } else {
            cout << query() << newl;
        }
    }
}