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
int t, n, cnt, x[50];
char s[50], ans[50];
bool check() {
    FOR0(i,n) {
        if(i == 0) {
            if(s[i] -'A' != x[i+1]) return false;
        } else if (i == n-1) {
            if(s[i]-'A' != x[i-1]) return false;
        } else {
            if(s[i]-'A' != (x[i-1]+x[i+1])%26) return false;
        }
    }
    cnt++;
    FOR0(i, n) ans[i] = x[i] +'A';
    return true;
}
int main() {
    SYNC
    scanf("%d%*c", &t);
    FOR(caseNum,1,t+1) {
        scanf("%s", s);
        n = strlen(s);
        cnt = 0;
        FOR0(i, 26) {
            FOR0(j, 26) {
                x[0] = i;
                x[1] = j;
                bool now = true;
                FOR(k,1,n-1) {
                    int val = s[k] - 'A';
                    if(val-x[k-1] >= 0 && val-x[k-1] < 26) x[k+1] = val-x[k-1];
                    else if(val-x[k-1]+26>=0 && val-x[k-1]+26 < 26) x[k+1] = val-x[k-1] + 26;
                    else now = false;
                }
                x[n-2] = s[n-1]-'A';
                if(now) check();
            }
        }
        ans[n] = '\0';
        if(cnt == 1) printf("Case #%d: %s\n",caseNum,ans);
        else if(cnt > 1)printf("Case #%d: AMBIGUOUS\n",caseNum);
    }

}