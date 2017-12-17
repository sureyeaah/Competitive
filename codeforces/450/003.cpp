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
const int N = 1e5 + 5;
int n, p[N], reach[N];
vi st[N];
int main() {
    SYNC
    stack<int> s;
    cin >> n;
    FOR(i, 1, n + 1) cin >> p[i];
    FOR(i, 1, n + 1) {
        while(!s.empty() && p[s.top()] < p[i]) s.pop();
        reach[i] = s.empty() ? 0: s.top() + 1;
        st[reach[i]].pb(p[i]);
        s.push(i);
    }

    int cur = 0, largest = -1; ii ans = mp(-inf, 0);
    cur = SZ(st[0]);
    FOR(i, 1, n + 1) {
        sort(st[i].begin(), st[i].end());
    }
    FOR(i, 1, n + 1) {
        int x = SZ(st[i+1]) - (lower_bound(st[i + 1].begin(), st[i + 1].end(),largest) - st[i+1].begin());
        ans = max(ans, mp(cur + x - (reach[i]==0), -p[i]));
        largest = max(largest, p[i]);
    }
    cout << -ans.ss;
}