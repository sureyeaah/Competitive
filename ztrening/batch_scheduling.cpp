// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
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
const int N =1e4 + 4;
int dp[N], t[N], f[N], n, s; int k[N];
int T(int l, int r) {return t[r] - t[l-1];}
int F(int l, int r) {return f[r] - f[l-1];}
int w(int j, int i) {return s * F(j, n) + F(j, i) * T(1, i);}
int calc(int j, int i) {return dp[j-1] + w(j, i); }
int main() {
    SYNC
    cin >> n >> s;
    FOR0(i, n) cin >> t[i+1] >> f[i+1];
    FOR0(i, n) t[i+1] += t[i];
    FOR0(i, n) f[i+1] += f[i];
    dp[0] = 0;
    V<P<int, int>> v;
    FOR(i, 1, n + 1) {
        while(!v.empty()) {
            auto cur = v.back();
            if(cur.ss >= i && calc(cur.ff, cur.ss) >= calc(i, cur.ss)) v.pop_back();
            else {
                int lt = max(i, cur.ss), rt = n, val = 0;
                while(lt <= rt) {
                    int mid = (lt + rt) >> 1;
                    if(calc(cur.ff, mid) < calc(i, mid)) lt = mid + 1;
                    else val = mid, rt = mid - 1;
                }
                if(val) v.push_back({i, val});
                break;
            }
        }
        if(v.empty()) v.push_back({i, 1});
        int lt = 0, rt = v.size() - 1, j = -1;
        while(lt <= rt) {
            int mid = (lt + rt) >> 1;
            if(v[mid].ss > i) rt = mid - 1;
            else lt = mid + 1, j = mid;
        }
        j = v[j].ff;
        dp[i] = calc(j, i);
    }
    cout << dp[n];
}