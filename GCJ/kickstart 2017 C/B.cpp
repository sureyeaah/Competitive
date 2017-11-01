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
#define N 60
int main() {
    SYNC
    int t, n, rc[N], cc[N];
    char x[N][N];
    cin >> t;
    FOR(caseNum,1,t+1) {
        cin >> n;
        memset(rc,0,sizeof rc);
        memset(cc,0,sizeof cc);
        FOR0(i, n) FOR0(j, n) {
            cin >> x[i][j];
            rc[i] += x[i][j] =='X';
            cc[j] += x[i][j] =='X';
        }
        bool r1= false, c1= false, ans = true;
        FOR0(i, n) if(rc[i] > 2 || !rc[i] || rc[i]==1 && r1) ans = false; else if(rc[i] == 1) r1 = true;
        FOR0(i, n) if(cc[i] > 2 || !cc[i] || cc[i]==1 && c1) ans = false; else if(cc[i] == 1) c1 = true;
        if(!c1 || !r1) ans = false;
        if(ans) {
            int cnt = 0;
            FOR0(i, n) {
                if(rc[i] == 1) {cnt++; continue;}
                vi v; int x1;
                FOR0(j, n) if(x[i][j] == 'X') v.pb(j);
                FOR0(j, n) if(j!= i && x[j][v[0]] == 'X') x1 = j;
                if(x1!=-1 && x[x1][v[1]] == 'X') cnt++;
            }
            ans = cnt==n;
        }
        cout << printCase() << (ans ? "POSSIBLE\n": "IMPOSSIBLE\n");
    }
}