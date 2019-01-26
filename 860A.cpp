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
#define EPS (1e-9)
#define PI 3.1415926535
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
    bitset<500> cons;
    cons.set();
    cons['a'] = 0;
    cons['e'] = 0;
    cons['u'] = 0;
    cons['i'] = 0;
    cons['o'] = 0;
    string s, out; cin >> s;
    s += "aa";
    FOR0(i, s.length() - 2) {
        if(cons[s[i]] && cons[s[i+1]] && cons[s[i+2]]) {
            int j = i;
            bool space = true;
            if(s[i] == s[i+1] && s[i+1] == s[i+2]) {
                space = false;
            }
            else if(s[i] == s[i+1]) j = i+1;
            else if(s[i+1] != s[i+2]) j = i+1;
            FOR(k,i,j+1) {
                out.pb(s[k]);
            }
            if(space) out.pb(' ');
            i = j;
        } else out.pb(s[i]);
    }
    cout << out;
}