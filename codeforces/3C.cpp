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
int checkWin(char grid[3][3], char x) {
    FOR0(i, 3) {
        int cnt = 0;
        FOR0(j, 3) if (grid[i][j] == x) cnt++;
        if(cnt == 3) return 1;
    }
    FOR0(j, 3) {
        int cnt = 0;
        FOR0(i, 3) if (grid[i][j] == x) cnt++;
        if(cnt == 3) return 1;
    }
    int cnt = 0;
    FOR0(i, 3) {
        if (grid[i][i] == x) cnt++;
    }
    if(cnt == 3) return 1;
    cnt = 0;
    FOR0(i, 3) {
        if (grid[i][2-i] == x) cnt++;
    }
    if(cnt == 3) return 1;
    return 0;
}
int main() {
    SYNC
    char grid[3][3];
    int cnt[2] = {};
    FOR0(i, 3) FOR0(j, 3) {
        cin >> grid[i][j];
        if (grid[i][j] == 'X') cnt[0]++;
        else if (grid[i][j] == '0') cnt[1]++;
    }
    if(cnt[0] - cnt[1] == 0 || cnt[0]-cnt[1] == 1) {
        int a = checkWin(grid, 'X');
        int b = checkWin(grid, '0');
        if(a && b || (a && cnt[0] == cnt[1]) || (b && cnt[0] != cnt[1])) cout << "illegal";
        else if(a) cout << "the first player won";
        else if(b) cout << "the second player won";
        else {
            if(cnt[0]+cnt[1] == 9 && !a && !b) cout << "draw";
            else cout << ((cnt[0]==cnt[1]) ? "first": "second");
        }
    } else cout << "illegal";
}