#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int f, r, f_cluster[20], r_cluster[20];
    double ratio[400];
    while(true) {
        scanf("%d", &f);
        if(f== 0) break;
        scanf("%d", &r);
        FOR0(i, f) scanf("%d", f_cluster+i);
        FOR0(i, r) scanf("%d", r_cluster+i);
        FOR0(i,f) {
            FOR0(j, r) {
                ratio[i*r + j] = (double)f_cluster[i]/(double)r_cluster[j];
            }
        }
        sort(ratio, ratio+(f*r));
        double max_spread = 0;
        for(int i = 1, n = f*r; i < n; i++)
            max_spread = MAX(max_spread, ratio[i]/ratio[i-1]);
        printf("%.2f\n",max_spread);
    }
}