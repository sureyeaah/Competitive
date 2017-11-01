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
    int money, numItems, price[111], favor[111], dp[10300];
    while(cin >> money) {
        cin >> numItems;
        FOR0(i,numItems) scanf("%d%d", price+i, favor+i);
        int curr = 1;
        int maxmoney = (money > 1800) ? money+200: money;
        FOR0(i, maxmoney+1) dp[i] = 0;
        FOR0(i,numItems) {
            FORD(j, maxmoney, price[i]) {
                if(dp[j-price[i]]) dp[j] = MAX(dp[j], dp[j-price[i]] + favor[i]);
            }
            dp[price[i]] = MAX(dp[price[i]], favor[i]);
        }
        int maxFavor = 0;
        if(money > 1800 && money <= 2000) {
            FOR0(i, money+1) {
                maxFavor = MAX(maxFavor, dp[i]);
            }
            FOR(i,2001,maxmoney+1) {
                maxFavor = MAX(maxFavor, dp[i]);
            }
        }
        else {
            FOR0(i,maxmoney+1) {
                maxFavor = MAX(maxFavor, dp[i]);
            }
        }
        cout << maxFavor << endl;
    }
}