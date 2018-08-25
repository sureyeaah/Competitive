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
    int t, n; string s;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        int ans = 1;
        FOR0(i, n) {
            int a = s[i] - 'a', b = s[n - i - 1] - 'a';
            map<int, int> cnt;
            if(a) cnt[a-1]++;
            if(a != 25) cnt[a+1]++;
            if(b) cnt[b-1]++;
            if(b != 25) cnt[b+1]++;
            int x = 0;
            for(auto r : cnt) if(r.second == 2) x = 1;
            ans &= x;
        }
        cout << (ans ? "YES": "NO" )<< endl;
    }
}