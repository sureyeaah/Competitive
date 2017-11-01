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
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int t,n,row,col,pop,dist[25][25];
    scanf("%d", &t);
    while(t--) {
        int city[25] = {}, sol[5], minVal = INF;
        scanf("%d", &n);
        FOR0(i, n) {
            scanf("%d%d%d", &row, &col, &pop);
            city[row*5 + col] = pop;
        }
        FOR0(i, 25) {
            FOR0(j, 25) {
                dist[i][j] = city[i]*(abs((int)(i/5) - (int)(j/5)) + abs((i%5) - (j%5)));
            }
        }
        FOR(a, 0, 25) {
            FOR(b, a+1, 25) {
                FOR(c, b+1, 25) {
                    FOR(d, c+1, 25) {
                        FOR(e, d+1, 25) {
                            int sum = 0;
                            FOR0(i, 25) {
                                int five[5] = {dist[i][a], dist[i][b], dist[i][c], dist[i][d], dist[i][e]};
                                sum += *min_element(five, five+5);
                                if(sum > minVal) break;
                            }
                            if(sum < minVal) {
                                minVal = sum;
                                sol[0] = a;
                                sol[1] = b;
                                sol[2] = c;
                                sol[3] = d;
                                sol[4] = e;                               
                            }
                        }
                    }
                }
            }
        }
        FOR0(i, 4) printf("%d ", sol[i]);
        printf("%d\n", sol[4]);
    }
}