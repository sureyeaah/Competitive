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
typedef vector<vi> vvi;

int main() {
    int T,n,height[2000],width[2000],lis[2001],lds[2001],longestIncreasing,longestDecreasing;
    scanf("%d", &T);
    FOR(caseNumber, 1, T+1) {
        scanf("%d", &n);
        FOR0(i, n) scanf("%d", &height[i]);
        FOR0(i, n) scanf("%d", &width[i]);
        FOR0(i, n) {
            lis[i] = lds[i] = width[i];
            int currHeight = height[i];
            FOR0(j, i) {
                if(height[j] < currHeight)
                    lis[i] = MAX(lis[i], lis[j]+width[i]);
                else if(height[j] > currHeight)
                    lds[i] = MAX(lds[i], lds[j]+width[i]);
            }
        }
        longestIncreasing = *max_element(lis, lis+n);
        longestDecreasing = *max_element(lds, lds+n);
        if(longestIncreasing >= longestDecreasing)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", caseNumber,longestIncreasing,longestDecreasing);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", caseNumber,longestDecreasing,longestIncreasing);
    }
}
