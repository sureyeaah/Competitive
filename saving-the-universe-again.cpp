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
int t, d, n; 
string p;
int val() {
    int cur = 1, ret = 0;
    FOR0(i, n) {
        if(p[i] == 'C') cur *= 2;
        else ret += cur;
    }
    return ret;
}
int main() {
    SYNC
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> d >> p;
        n = p.length();
        int ans = 0;
        while(val() > d) {
            int changed = 0;
            FORD(i, 0, n-1) {
                if(p[i] == 'C' && p[i+1] == 'S') {
                    swap(p[i], p[i+1]);
                    ans++;
                    changed = 1;
                    break;
                }
            }
            if(!changed) break;
        }
        cout << printCase();
        if(val() > d) {
            cout << "impossible" << endl;
        } else cout << ans << endl;
    }
}