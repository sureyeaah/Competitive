#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 100005
int n, a, b;
ll h[N], tmp[N];
bool solve(ll moves) {
    ll val = 0;
    FOR0(i, n) {
        tmp[i] = (h[i] - 1)/b + 1 >= moves ? h[i] - b*moves: 0; 
        if(tmp[i] > 0) val += (tmp[i] - 1)/(a-b) + 1;
    }
    return val <= moves;
}
int main() {
    SYNC
    cin >> n >> a >> b;
    FOR0(i, n) cin >> h[i];
    ll l = 0, r = 1e15;
    while(l < r) {
        ll mid = (l + r) >> 1;
        if(solve(mid)) {
            r = mid ;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}