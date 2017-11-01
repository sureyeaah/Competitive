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
#define maxn 30000
int main() {
    SYNC
    int n, m;
    cin >> n>> m;
    int dist[maxn];
    FOR0(i, maxn) dist[i] = INF;
    dist[n] = 0;
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, n));
    while (!pq.empty()) { // main loop
        ii front = pq.top(); pq.pop();
        int d = front.first, u = front.second;
        if (d > dist[u]) continue;
        if(u*2 < maxn && dist[u*2] > dist[u] + 1) pq.push(ii((dist[u*2] = dist[u] + 1), u*2));
        if(u-1>=0 && dist[u-1] > dist[u] + 1) pq.push(ii((dist[u-1] = dist[u] + 1), u-1));
    }
    cout << dist[m];
}