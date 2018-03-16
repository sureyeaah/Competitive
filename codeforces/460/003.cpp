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
const int N = 2005;
char g[N][N]; int n, m, k;
int main() {
    SYNC
    cin >> n >> m >> k;
    FOR0(i, n) FOR0(j, m) cin >> g[i][j];
    ll ans = 0;
    FOR0(i, n) {
        int j = 0, cur = 0;
        while(j < m) {
            if(g[i][j] == '.') cur++;
            else if(g[i][j] == '*') {
                ans += max(0, cur - k + 1);
                cur = 0;
            }
            j++;
        }
        if(cur) {
            ans += max(0, cur - k + 1);
            cur = 0;
        }
    }
    if(k > 1) {
        FOR0(j, m) {
            int i = 0, cur = 0;
            while(i < n) {
                if(g[i][j] == '.') cur++;
                else if(g[i][j] == '*') {
                    ans += max(0, cur - k + 1);
                    cur = 0;
                }
                i++;
            }
            if(cur) {
                ans += max(0, cur - k + 1);
                cur = 0;
            }
        }
    }
    cout << ans;
}