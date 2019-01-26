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
int t, n; string s;
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> s;
        V<int> v;
        int x = 0;
        ll ans = 0;
        FOR0(i, n) {
            char c = s[i];
            if(c == '#') {
                v.push_back(i+x);
                ans += x;
                if(i+1 != v.size()) x++;
                // cerr << i+x << " ";
                
            } else {
                x--;
                if(x<0) x = 0;
            }
        }
        if(v.size()>0 && v.size() != n && v.back() >= n-1){
            cout << -1 << endl; continue;
        }
        FOR0(i, v.size()) ans += v[i] - i;
        cout << ans << endl;
    }
}