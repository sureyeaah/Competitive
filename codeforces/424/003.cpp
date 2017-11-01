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
#define N 2005
#define ST ((int)1e7)
int main() {
    SYNC
    int ans = 0;
    int n, k, a[N], b[N]; int pre[N], sum = 0;
    vi cnt(2*ST+1,0);
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    FOR0(i, k) cin >> b[i];
    FOR0(i, n) pre[i] = sum = sum + a[i];
    sort(pre, pre + n); pre[n] = INF;
    FOR0(i, k) {
        FOR0(j, n) {
            if(pre[j] != pre[j+1]) cnt[b[i]-pre[j] + ST]++;
        }
    }
    for(int x : cnt) if(x == k) ans++;
    cout << ans;
}