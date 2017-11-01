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
int main() {
    SYNC
    vvi v(N);
    int cases, n, days, d[N], t[N], s[N];
    cin >> cases;
    while(cases--) {
        cin >> n >> days;
        FOR0(i, days+1) v[i].clear();
        FOR0(i, n) cin >> d[i] >> t[i] >> s[i];
        FOR0(i, n) v[d[i]].pb(i);
        priority_queue<ii> pq;
        FOR(i,1,days+1) {
            for(int j : v[i]) {
                pq.push(mp(s[j], j));
            }
            if(pq.empty()) continue;
            t[pq.top().ss]--;
            if(t[pq.top().ss] == 0) pq.pop();
        }
        ll ans = 0;
        while(!pq.empty()) {
            ans += (ll)pq.top().ff*(ll)t[pq.top().ss];
            pq.pop();
        }
        cout << ans << '\n';
    }
}