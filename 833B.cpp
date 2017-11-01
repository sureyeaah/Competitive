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
#define N 350005
int n, k, cnt[N] = {} cnt2[N] = {}, a[N], val[55] = {};
ii getPos(int l, int r, int i) {
    FOR(i,l,r+1) {
        cnt[a[i]]++;
    }
    ii ret = mp(val[i], r);
    int lv = 0, rv = val[i];
    FOR(i,l,r) {
        cnt2[a[i]]++;
        if(cnt2[a[i]] == 1) {
            lv++;
        }
        if (cnt[a[i]] - cnt2[a[i]] == 0) {
            cnt[a[i]] = cnt2[a[i]] = 0;
            rv--;
        }
        ret = max(ret, mp(cur, i));
    }
    return ret;
}

int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    FOR0(i, n) {
        if(!cnt[a[i]]) {
            val[0]++;
            cnt[a[i]] = 1;
        }
    }
    memset(cnt, 0, sizeof cnt);
    lt[0] = 0; rt[0] = n-1;
    vis.clear();
    FOR(cur, 1, k) {
        ii p = mp(0, 0);
        FOR0(i, cur) p = max(p, getPos(lt[i], rt[i], i));
    }
}   