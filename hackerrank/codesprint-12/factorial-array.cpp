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
#define mod (1000000000)
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
const int B = 330, N = 1e5 + 5, S = 50;
int sq, a[N], n, m, type, fac[S];
int cnt[B][S] = {}, add[B] = {};
void update(int l, int r) {
    int b = l/sq;
    for(int i = l, j = min(n, sq*(b + 1)); i < j && i <= r; i++) {
        cnt[b][a[i]]--;
        a[i] = min(S - 1, a[i] + 1);
        cnt[b][a[i]]++;
    }
    b = r/sq;
    if(b == l/sq) return;
    for(int i = b*sq; i <= r; i++) {
        cnt[b][a[i]]--;
        a[i] = min(S - 1, a[i] + 1);
        cnt[b][a[i]]++;
    }
    for(int i = l/sq + 1, j = r/sq - 1; i <= j; i++) {
        add[i]++;
    }
}
int query(int l, int r) {
    int ans = 0;
    int b = l/sq;
    for(int i = l, j = min(n, sq*(b + 1)); i < j && i <= r; i++) {
        ans = (ans + fac[min(S-1, add[b] + a[i])]) % mod;
    }
    // DEBUG(ans);
    if(b == r/sq) return ans;
    b = r/sq;
    for(int i = b*sq; i <= r; i++) {
        ans = (ans + fac[min(S-1, add[b] + a[i])]) % mod;
    }
    // DEBUG(ans);
    for(int i = l/sq + 1, j = r/sq - 1; i <= j; i++) {
        for(int k = 0; k + add[i] < S; k++) ans = (ans + fac[k + add[i]] * 1LL * cnt[i][k]) % mod;
    }
    return ans;
}
int main() {
    SYNC
    fac[0] = 1;
    FOR(i, 1, S) fac[i] = fac[i-1] * 1LL * i % mod;
    cin >> n >> m;
    sq = pow(n, 0.5);
    FOR0(i, n) {
        cin >> a[i];
        a[i] = min(a[i], S - 1);
    }
    int b = 0;
    for(int i = 0; i < n; i += sq) {
        for(int j = i; j < n && j < i + sq; j++) {
            cnt[b][a[j]]++;
        }
        b++;
    }
    int l, r;
    while(m--) {
        cin >> type >> l >> r;
        l--; r--;
        if(type == 1) {
            update(l, r);
        } else if(type == 2) {
            cout << query(l, r) << newl;
        } else if(type == 3) {
            r++;
            int b = l/sq;
            memset(cnt[b], 0, sizeof(cnt[b]));
            // FOR0(i, S) cerr << cnt[b][a[i]] << " ";
            for(int i = b * sq; i < n && i < (b+1) * sq; i++) {
                if(i == l) a[i] = min(r, S - 1);
                else a[i] = min(S - 1, a[i] + add[b]);
                cnt[b][a[i]]++;
            }
            add[b] = 0;
        }
    }
}