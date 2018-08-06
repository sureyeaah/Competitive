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
#define L 1000
#define N 500
bool poss(string& s, int k) {
    unordered_set<string> st;
    FOR0(i, s.length() - k + 1) st.insert(s.substr(i, k));
    return (st.size() == 1 << k);
}
int solve(string& s) {
    int l = 1, r = 20;
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(poss(s, mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}
int main() {
    SYNC
    string st[N], nd[N];
    int n, m, a, b, ans[N];
    cin >> n;
    FOR0(i, n) {
        cin >> st[i+1];
        nd[i+1] = st[i+1];
        ans[i+1] = solve(st[i+1]);
    }
    cin >> m;
    FOR(i,n+1,n + m + 1) {
        cin >> a >> b;
        st[i] = st[a];
        if(st[i].length() < L) {
            int len = min(L - st[i].length(), st[b].length());
            st[i] += st[b].substr(0, len);
        }
        nd[i] = nd[b];
        if(nd[i].length() < L) {
            int len = min(L - nd[i].length(), nd[a].length());
            nd[i] = nd[a].substr(nd[a].length() - len, len) + nd[i];
        }
        int la = min((int)nd[a].length(), L);
        int lb = min((int)st[b].length(), L);
        string x = nd[a].substr(nd[a].length() - la, la);
        x += st[b].substr(0, lb);
        ans[i] = solve(x);
        ans[i] = max(ans[i], max(ans[a], ans[b]));
        cout << ans[i] << newl;
    }
}