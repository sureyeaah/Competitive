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
#define printCase() "Case " << caseNum << ": "
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

int main() {
    SYNC
    int t, cnt[3], n;
    string s;
    cin >> t;
    FOR(caseNum,1,t+1) {
        memset(cnt,0,sizeof cnt);
        n = 0;
        cin >> s; n = (int)s.length();
        FOR0(i, n) cnt[(s[i]-'0') % 3]++;
        int m = (cnt[1] + 2*cnt[2]) % 3, ans = 1;
        if(n == 1) ans = 0;
        else if(m == 0) {
            ans = (cnt[0] % 2) ^ (cnt[1] + cnt[2] != 1);
        } else if(m == 2) {
            if(cnt[2]) ans = (cnt[0] % 2) ^ (cnt[1] + cnt[2] - 1 == 1);
        } else {
            if(cnt[1]) ans = (cnt[0] % 2) ^ (cnt[1] + cnt[2] - 1 == 1);
        }
        cout << printCase() << (ans ? 'T': 'S') << '\n';
    }
}