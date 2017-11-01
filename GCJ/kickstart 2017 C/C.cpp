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
#define N 3
int t, n, q, ans[N], s[N]; char x;
int count(int a, int b) {
    int cnt = 0, res = (a^(~b))&((1 << q) - 1);
    FOR0(i, q) if(res&(1<<i)) cnt++;
    return cnt;
}
int solve() {
    int ret = 0;
    FOR0(i,1<<q) {
        if(count(i, ans[0]) == s[0]) ret = max(ret, count(i, ans[1]));
    }
    return ret;
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum,1,t+1) {
        cin >> n >> q;
        FOR0(i, n+1) {
            ans[i] = 0;
            FOR0(j, q) {
                cin >> x;
                if(x == 'T') ans[i] |= 1 << (j);
            }
        }
        FOR0(i, n) cin >> s[i]; 
        cout << printCase() << solve() << endl;
    }
}