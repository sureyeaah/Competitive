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
const int N = 1e5 + 5;
int n, k, x[N];
int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> x[i];
    vector<int> v1({0}), v2({0});
    FOR0(i, n) {
        if(x[i] > 0) v1.push_back(x[i]);
        else v2.push_back(-x[i]);
    }
    sort(v2.begin(), v2.end());
    // FOR(i, 1, v1.size()) v1[i] += v1[i-1];
    // FOR(i, 1, v2.size()) v2[i] += v2[i-1];
    int ans = inf;
    for(int x : v1) cerr << x << endl;
        for(int x : v2) cerr << x << endl;
    FOR(i, 0, min(k+1, (int)v1.size())) {
        if(k - i < v2.size()) {
            ans = min(ans, v1[i] + v1[i] + v2[k-i]);
        }
    }
    swap(v1, v2);
    FOR(i, 0, min(k+1, (int)v1.size())) {
        if(k - i < v2.size()) {
            ans = min(ans, v1[i] + v1[i] + v2[k-i]);
        }
    }
    if(v1.size() > k) ans = min(ans, v1[k]);
    if(v2.size() > k) ans = min(ans, v2[k]);
    cout << ans;
}