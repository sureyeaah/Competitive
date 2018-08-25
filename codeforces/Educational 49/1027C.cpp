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
const int N = 1e6 + 6;
int t, n, a[N];
int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n;
        map<int, int> cnt;
        FOR0(i, n) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int l = 0; ld cur = 1e18;
        int a1 = 0, a2 = 0;
        for(auto r: cnt) {
            if(r.second < 2) continue;
            if(l) {
                if(!a2 || (r.first * 1LL * a1 < a2 * 1LL * l)) {
                    a1 = l, a2 = r.first;
                }
            }
            l = r.first;
        }
        for(auto r : cnt) {
            if(r.second >= 4) {
                a1 = a2 = r.first;
            }
        }
        cout << a1 << " " << a2 << " ";
        cout << a1 << " " << a2 << endl;
    }
}