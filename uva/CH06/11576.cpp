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
int cases, len, words, back[105];
string s[105]; 
void process(string& p) {
    int i = 0, j = -1; back[0] = -1;
    while(i < len) {
        while(j >= 0 && p[i] != p[j]) j = back[j];
        i++; j++;
        back[i] = j;
    }
}
int match(string& p, string& s) {
    int i = 0, j = 0;
    while(i < len) {
        while(j >= 0 && s[i] != p[j]) j = back[j];
        i++; j++;
    }
    return j;
}
int main() {
    SYNC
    cin >> cases;
    FOR(caseNum,1,cases+1) {
        cin >> len >> words;
        int ans = len;
        FOR0(i, words) cin >> s[i];
        FOR(i,1,words) {
            process(s[i]);
            ans += len - match(s[i], s[i-1]);
        }
        cout << ans << '\n';
    }
}