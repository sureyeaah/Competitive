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
#define N 1005
#define mod (7 + (int)1e9)
int n, longest[N] = {}, lim[26], dp[N] = {};
int main() {
    SYNC
    string s;
    cin >> n >> s;
    FOR0(i, 26) cin >> lim[i];
    FOR0(i, n) {
        longest[i] = 1;
        int cur = INF;
        FOR(j, i, n) {
            cur = min(cur, lim[s[j] - 'a']);
            if(cur < j-i+1) break;
            longest[i] = j-i+1;
        }
    }
    FORD(i,0,n) {
        int cur = 1;
        cur += (dp[i+1] - dp[min(n, i + longest[i])])%mod;
        cur %= mod;
        if(cur < 0) cur += mod;
        if(!i) cout << cur << endl;
        dp[i] = (cur + dp[i + 1]) % mod;
    }
    cout << *max_element(longest,longest+n)  << '\n';
    // memset(dp, 0, sizeof dp);
    // FORD(i,0,n-1) {
    //     if(i + longest[i] - 1 >= n) cur = 1;
    //     cur += (dp[i+1] - dp[min(n, i + longest[i])])%mod;
    //     cur %= mod;
    //     if(cur < 0) cur += mod;
    //     dp[i] = (cur + dp[i + 1]) % mod;
    // }
}