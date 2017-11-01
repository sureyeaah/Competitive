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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    SYNC;
    int n, a[100005];
    cin >> n; FOR0(i, n) cin >> a[i];
    sort(a, a+n);
    ll cnt[3] = {};
    ll ans = 0;
    FOR0(i, n) if(a[i] == a[0]) cnt[0]++;
    if(cnt[0] >= 3) ans = (cnt[0]*(cnt[0]-1)*(cnt[0]-2)) / 6;
    else if(cnt[0] == 2) {
        FOR0(i, n) if(a[i] == a[2]) cnt[1]++;
        ans = cnt[1];
    } else if (cnt[0] == 1) {
        FOR0(i, n) if(a[i] == a[1]) cnt[1]++;
        if(cnt[1] == 1) {
            FOR0(i, n) if(a[i] == a[2]) cnt[2]++;
            ans = cnt[2];
        } else ans = (cnt[1]*(cnt[1]-1)) / 2;
    }
    cout << ans << endl;
}