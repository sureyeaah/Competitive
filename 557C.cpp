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
#define INF ((int)2e9)
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
int cnt[N] = {}, n, sum[N], l[N], d, dcnt[205];
ii t[N];
int main() {
    SYNC
    cin >> n;
    FOR0(i, n) {cin >> l[i]; cnt[l[i]]++;}
    FOR0(i, n) {
        cin >> d;
        t[i] = mp(l[i], d);
    }
    sort(t, t + n);
    sum[n] = 0;
    FORD(i,0,n) sum[i] = sum[i+1] + t[i].ss;
    int ans = INF;
    FOR0(i,n) {
        if(t[i].ff != t[i+1].ff) {
            int rem = max(i - 2*cnt[t[i].ff] + 2, 0);
            int cur = 0;
            FOR0(j, 201) {
                if(rem <= 0) break;
                cur += min(dcnt[j], rem)*j;
                rem -= dcnt[j];
            }
            ans = min(ans, cur + sum[i+1]);
            FOR(j,i-cnt[t[i].ff]+1,i+1) dcnt[t[j].ss]++;
        }
    }
    cout << ans << endl;
}