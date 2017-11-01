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
    string s, a, b, out;
    cin >> s >>a >> b;
    out = s;
    int i = 0;
    while(i < s.length()) {
        bool b1 = true, b2 = true;
        if(i+a.length() > s.length()) break;
        for(int j = i; (j-i < a.length()); j++) {
            if(a[j-i] != s[j]) b1 = false;
            if(b[j-i] != s[j]) b2 = false;
        }
        if(b1 || b2) {
            string& rep = b2 ? a : b;
            FOR0(j, rep.length()) out[i++] = rep[j];
        } else i++;
    }
    cout << out;
}