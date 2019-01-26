// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);

int main() {
    SYNC
    int n, l; cin >> n;
    priority_queue<int, V<int>, greater<int>> pq;
    V<P<int,int>> ans;
    FOR0(i, n) {
        cin >> l;
        if((l&1)==0) ans.push_back(make_pair(l, l/2));
        else pq.push(l);
    }
    while(SZ(pq)) {
        int x = pq.top(); pq.pop();
        if(!SZ(pq)) {
            cout << -1; return 0;
        }
        int y = pq.top(); pq.pop();
        if(y == x) continue;
        ans.push_back(make_pair(y, x));
        ans.push_back(make_pair(y-x, (y-x)/2));
    }
    cout << SZ(ans) << endl;
    for(auto x : ans) cout << x.ff << " " << x.ss << endl;
}