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
int ft[N] = {};
int n, r[N], c[N];
char x[N];
void update(int i, int val) {
    i++;
    for(;i<=n;i+=i&(-i)) ft[i] += val;
}
int query(int i) {
    i++;
    int ret = 0;
    for(;i;i-=i&(-i)) ret += ft[i];
    return ret;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        cin >> x[i];
    }
    FOR0(i, n) {cin >> r[i]; r[i]--;}
    FOR0(i, n) cin >> c[i];
    ll ans = 0;
    FOR0(i, n) {
        if((x[i] - '0') ^ ((query(i) ) & 1)) {
            ans += c[i];
            update(i, 1); update(r[i]+1, -1);
        }
    }
    cout << ans;
}