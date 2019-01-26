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
const int N = 2e5 + 5; int n, x, y, a[N][2];
int bs(int lt, int rt, int r) {
    int ans = inf;
    while(lt <= rt) {
        int m = (lt + rt) >> 1, mid = 2*m-r;
        int f=0;
        FOR(i,1,n-mid+2) {
            int j = i+mid-1;
            int X = a[n][0]-(a[j][0]-a[i-1][0]); X=abs(x-X);
            int Y = a[n][1]-(a[j][1]-a[i-1][1]); Y=abs(y-Y);
            // cerr << i << " " << j << " " << X<<" "<<Y << endl;
            if(X+Y<=mid&&!((mid-X-Y)&1)){
                f=1;
            }
        }
        if(f) ans=mid,rt=m-1;
        else lt=m+1;
    }
    return ans;
}
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {
        char c; cin >> c;
        a[i+1][0] = a[i][0];
        a[i+1][1] = a[i][1];
        if(c == 'L' || c == 'R') {
            a[i+1][0] += c=='R'?1:-1;
        } else {
            a[i+1][1] += c=='U'?1:-1;
        }
    }
    cin>>x>>y;
    int ans = min(bs(1,n/2,0), bs(1,(n+1)/2,1));
    if(a[n][0]==x&&a[n][1]==y)ans=0;
    if(ans==inf) ans=-1;
    cout << ans;
}