#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
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
    bool possible[1010];
    int t, n, p, bar[21];
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &p);
        FOR0(i, p) scanf("%d", bar+i);
        FOR(i,1,n+1) possible[i] = false;
        possible[0] = true;
        FOR0(j, p) {
             FORD(i,n-bar[j],0) {
                if(possible[i])
                    possible[i+bar[j]] = true;
            }
        }
        if(possible[n]) printf("YES\n");
        else printf("NO\n");
    }
}