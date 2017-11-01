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

int main() {
    SYNC
    int cases, cnt[2][26]; string s[2];
    cin >> cases;
    while(cases--) {
        memset(cnt, 0, sizeof cnt);
        FOR0(i, 2) {
            cin >> s[i];
            FOR0(j, s[i].length()) cnt[i][s[i][j] - 'a']++;
        }
        int win = 1;
        bool a =false, b =false, c = false;
        FOR0(i, 26) {
            if((!cnt[0][i])^(!cnt[1][i])) {
                if(cnt[0][i]) a = true;
                else b = true;
                if(cnt[0][i] > 1) c = true;
            }
        }
        if((a && !b) || (a && b && c)) win = 0;
        cout << (char)('A' + win) << '\n';
    }
}