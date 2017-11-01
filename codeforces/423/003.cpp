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
#define LEN 3000005
#define N 100005
int main() {
    SYNC
    char out[LEN] = {};
    string s[N];
    int n,k,t; vii vec;
    cin >> n;
    FOR0(i, n) {
        cin >> s[i];
        cin >> k;
        while(k--) {
            cin >> t;
            vec.pb(mp(t-1,i));
        }
    }
    sort(vec.begin(), vec.end());
    int ind = 0;
    for(ii& v: vec) {
        int l = s[v.ss].length();
        while(ind < v.ff) out[ind++] = 'a';
        while(ind < v.ff+l) {out[ind]  = s[v.ss][ind-v.ff]; ind++;}
        out[ind] = '\0';
    }
    printf("%s", out);
}