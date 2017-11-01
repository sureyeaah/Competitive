#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 2000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int n,m,s,coins[40][2],dp[302][302];
    scanf("%d", &n);
    while(n--) {
        int mincoins = INF;
        scanf("%d%d", &m, &s);
        FOR0(i, m) scanf("%d%d",&coins[i][0],&coins[i][1]);
        FOR0(x,s+1) {
            double temp = sqrt(s*s - x*x);
            if(temp == (int)temp) {
                int y = (int)temp;
                dp[0][0] = 0;
                FOR0(i,x+1) {
                    FOR0(j,y+1) {
                        FOR0(k, m) {
                            if(i >= coins[k][0] && j >= coins[k][1]) dp[i][j] = MIN(dp[i][j], dp[i - coins[k][0]][j - coins[k][1]] + 1);
                        }
                        dp[i+1][j] = dp[i][j+1] = INF;
                    }
                }
                mincoins = MIN(mincoins, dp[x][y]);
            }
        }
        if(mincoins == INF) cout << "not possible" << endl; 
        else cout << mincoins << endl;
    }
}