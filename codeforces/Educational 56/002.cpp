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
    int t; string s;
    cin >> t;
    while(t--) {
        int n; cin >> s; n = s.length();
        int ans = 0;
        int pal=1;
        FOR0(i, n) if(s[i] != s[n-i-1]) pal=0;
        if(pal) {
            FOR0(i, n-1) {
            if(s[i] != s[i+1]) {
                ans = 1;
                swap(s[i], s[i+1]); break;
            }
        }
        }
        if(ans||!pal) cout << s << endl;
        else cout<<-1<<endl;
    }
}