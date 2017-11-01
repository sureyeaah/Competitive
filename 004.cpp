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
#define SYNC ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define N 5005

int main() {
    SYNC
    string s; int n, ans[N] = {}, k[N][N];
    cin >> s; n = s.length();
    bitset<N> pal[N];
    FOR0(i, n) pal[i][i] = 1;
    FOR0(i, n) k[i][i] = 1;
    ans[1] = n;
    FOR(len, 2, n + 1) {
        for(int i = 0; ; i++) {
            int j = i + len - 1;
            if(j >= n) break;
            pal[i][j] = (len == 2 ? 1: pal[i+1][j-1]) && (s[i] == s[j]);
            if(pal[i][j]) {
                int mid = i + (len >> 1) - 1;
                if(pal[i][mid]) k[i][j] = k[i][mid] + 1;
                else k[i][j] = 1;
                ans[k[i][j]]++;
            }
        }
    }
    FORD(i,1,n+1) ans[i] += ans[i+1];
    FOR(i,1,n+1) cout << ans[i] << " ";
}