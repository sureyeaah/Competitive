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
#define N 10005
string s; int k;
// string recurse(int l, int r) {
//     if(l > r) return "";
//     int i = l;
//     while(i <= r && dp[r+1][s[i]-'a'] - dp[l][s[i]-'a'] >= k) i++;
//     if(i > r) return s.substr(l, r - l + 1);
//     string ls = s.substr(l, i - l), rs = r-i-2 > 0 ? s.substr(i+1, r-i-2): "";
//     return ls.length() < rs.length() ? rs : ls.length() > rs.length() ? ls : max(ls, rs);
// }
int main() {
    SYNC
    int cnt[26] = {};
    cin >> s >> k;
    FOR0(i, s.length()) {
        cnt[s[i] - 'a']++;
    }
    FOR0(i, s.length()) {
        if(cnt[s[i] - 'a'] >= k) cout << s[i];
    }
}