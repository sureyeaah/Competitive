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
#define N 300005
int main() {
    SYNC
    ll ans = 0;
    int n, k, c[N], aa[N];
    cin >> n >> k;
    priority_queue<ii> pq;
    FOR0(i, n) {
        cin >> c[i];
        ans += -c[i] * 1LL * (i+1);
        pq.push(mp(c[i], i+1));
        if(i+1 > k) {
            ans += 1LL*pq.top().ff*(i+1);
            aa[pq.top().ss-1] = i+1;
            pq.pop();
        }
    }
    int cur = n - pq.size() + k;
    while(!pq.empty()) {
        cur++;
        ans += 1LL*pq.top().ff*(cur);
        aa[pq.top().ss-1] = cur;
        pq.pop();
    }
    cout << ans << endl;
    FOR0(i, n) cout << aa[i] << " ";
}