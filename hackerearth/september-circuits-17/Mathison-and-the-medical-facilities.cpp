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
#define inf ((int)2e9)
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
#define N 505
#define M 2005
int n, k, m, will[M][N], cost[N], spent = 0, gained = 0, profitDueTo[N] = {};
bitset<N> used, isExp;
priority_queue<ii> pq[M];
int add(int x) {
    memset(profitDueTo, 0, sizeof profitDueTo);
    int ans = 0;
    spent += cost[x]; profitDueTo[x] -= cost[x];
    used[x] = 1;
    FOR(i,1,m+1) {
        while(!pq[i].empty() && !used[pq[i].top().ss])
            pq[i].pop();
        pq[i].push(mp(will[i][x], x));
        ans += pq[i].top().ff;
        profitDueTo[pq[i].top().ss] += pq[i].top().ff;
    }
    return ans;
}
int remove(int x) {
    int ans = 0;
    spent -= cost[x];
    used[x] = 0;
    FOR(i,1,m+1) {
        while(!pq[i].empty() && !used[pq[i].top().ss])
            pq[i].pop();
        if(!pq[i].empty()) ans += pq[i].top().ff;
    }
    return ans;
}
void isExpensive() {
    FOR(i,1,n+1) {
        int cnt = 0;
        FOR(j,1,m+1) {
            if(will[j][i] >= 500) cnt++;
        }
        if(cnt == m) {
            isExp[i] = 1;
        }
    }
}
int main() {
    SYNC
    std::srand ( unsigned ( std::time(0) ) );
    cin >> n >> k >> m;
    FOR(i,1,m+1) FOR(j,1,n+1) cin >> will[i][j];
    FOR(i,1,n+1) cin >> cost[i];
    int t = 25*n;
    isExpensive();
    if(1) {
        vi arr;
        FOR(i,1,n+1) if(!isExp[i]) arr.pb(i);
        random_shuffle(arr.begin(), arr.end());
        FOR0(i,k-isExp.count()) {
            gained = add(arr[i]);
        }
    }
    while(t--) {
        int nxt = (rand() % n) + 1;
        int worst = (rand() % n) + 1;
        if(isExp[nxt] || isExp[worst] || used[nxt] || !used[worst]) continue;
        int prevAns = gained - spent;
        add(nxt);
        remove(worst);
        if(gained - spent < prevAns) {
            add(worst);
            remove(nxt);
        }
    }
    if(isExp.count() > k) {
        FOR(i,1,n+1) {
            if(!k) break;
            if(isExp[i])  {
                cout << i << " ";
                k--;
            }
        }
    }
    else FOR(i,1,n+1) if(used[i] || isExp[i]) cout << i << " ";
}