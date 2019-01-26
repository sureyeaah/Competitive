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
int t, n, a, b;
unordered_map<int, int> x;
void ins(int p, int q) {
    auto it = x.find(p + q);
    if(it == x.end()) {
        x[p + q] = x[p] + 1;
    }
    else {
        x[p + q] = min(x[p] + 1, x[p + q]);
    }
}
int main() {
    SYNC;
    cin >> t;
    while(t--) {
        cin >> n >> a >> b; b = -b;
        x.clear();
        queue<P<int,int>> q({{0, 1}}); x[0] = 1;
        while(q.!empty()) {
            int c = q.front().first, dist = q.front().second; q.pop();
            ins(c, a);
            if(x[c + a] != n + 1) q.push(c + a);
            ins(c, b);
            if(x[c + b] != n + 1) q.push(c + b);
        }
        cout << x.size() << endl;
    }
}
