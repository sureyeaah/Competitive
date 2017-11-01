#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e8
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int n, m;
    int minMoves[51][3];
    char s[51][51];
    cin >> n >> m;
    while(getchar() != '\n') {}
    FOR0(i, n) {
        scanf("%s", s[i]);
    }
    FOR0(i, n) {
        minMoves[i][0] = minMoves[i][1] = minMoves[i][2] = INF;
        FOR0(j, m) {
            char cc = s[i][j];
            int currmoves = min(j, m-j);
            if(cc >= 'a' && cc <= 'z') {
                minMoves[i][0] = min(minMoves[i][0], currmoves);
            } else if(cc >= '0' && cc <= '9') {
                minMoves[i][1] = min(minMoves[i][1], currmoves);
            } else if(cc == '#' || cc == '*' || cc == '&') {
                minMoves[i][2] = min(minMoves[i][2], currmoves);                
            }
        }
    }
    int output = INF;
    FOR0(i, n) {
        FOR0(j, n) {
            if(i == j) continue;
            FOR0(k, n) {
                if(k == i || k == j) continue;
                output = min(output, minMoves[i][0] + minMoves[j][1] + minMoves[k][2]);
            }
        }
    }
    cout << output << endl;
}