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
int main() {
    SYNC
    string s;
    int n, x, a[N], need = 0, cnt[10] = {};
    cin >> s >> n;
    FOR0(i, s.length()) a[i] = s[i] - '0';
    FOR0(i, n) {
        cin >> x;
        need |= 1 << x;
    }
    int l = 0, r = 0, cur = 0;
    ll ans = 0;
    n = s.length();
    while(l < n && r < n || cur == need) {
        if(r != n && cur != need) {
            if(need & (1 << a[r])) {
                cur |= 1 << a[r];
                cnt[a[r]]++;
            }
            r++;
        }
        if(cur == need) {
            ans += n - r + 1;
            if(need & (1 << a[l])) {
                cnt[a[l]]--;
                if(!cnt[a[l]]) cur ^= 1 << a[l];
            }
            l++;
        }
    }
    cout << ans;
}