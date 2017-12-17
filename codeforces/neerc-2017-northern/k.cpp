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
#define inf ((int)1e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 105;
char out[N][N];
int main() {
    ifstream cin("kotlin.in");
    ofstream cout("kotlin.out");
    SYNC

    int h, w, n;
    cin >> h >> w >> n;
    FOR(i, 0, (h-1)/2 + 1) {
        FOR(j, 0, (w-1)/2 + 1) {
            if((i+1) * (j+1) == n) {
                FOR0(x, h) FOR0(y, w) out[x][y] = '.';
                for(int x = 1; x < h && i; x += 2) {
                    for(int y = 0; y < w; y++) {
                        out[x][y]= '#';
                    }
                    i--;
                }
                for(int y = 1; y < w && j; y += 2) {
                    for(int x = 0; x < h; x++) {
                        out[x][y]= '#';
                    }
                    j--;
                }
                FOR0(x, h) {
                    FOR0(y, w) cout << out[x][y];
                    cout << newl;
                }
                return 0;
            }
        }
    }
    cout << "Impossible";
}