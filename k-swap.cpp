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
int n, k, a[N], ft[N] = {}, entry[N], out[N], tmp[N] = {};
void update(int i) {
    for(;i<=n;i+=i&-i) ft[i]++;
}
int query(int i) {
    int ret = 0;
    for(;i;i-=i&(-i)) ret += ft[i];
    return ret;
}
int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    stack<int> s;
    FOR0(i, n) {
        while(!s.empty() && a[s.top()] > a[i] && a[s.top()] <= a[i] + k) s.pop();
        entry[i] = s.empty() ? 0 : entry[s.top()] + 1;
        tmp[i] = query(entry[i] + 1);
        update(entry[i] + 1);
        s.push(i);
    }
    FOR0(i, n) {
        int x = entry[i] + query(entry[i] + 1) - tmp[i];
        out[x] = a[i];
    }
    FOR0(i, n) cout << out[i] << " ";
}