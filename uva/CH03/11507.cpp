#include <algorithm>
#include <iostream>
#include <vector>
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
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int main(){
    int n, money, price[10000];
    while(scanf("%d", &n) == 1) {
        FOR0(i, n) {
            scanf("%d", price+i);
        }
        sort(price, price+n);
        scanf("%d", &money);
        int mid = lower_bound(price, price+n, (int)(money/2)) - price;
        int curr =  ((int)(money/2) == price[mid])? mid : mid-1;
        int other = mid;
        do {
            other = lower_bound(price+other, price+n, money - price[curr]) - price;
            if(price[curr] + price[other] == money) break;
            // other++;
            curr = MIN(lower_bound(price, price+curr+1, money - price[other]) - price, curr-1);
        } while(price[curr] + price[other] != money);
        printf("Peter should buy books whose prices are %d and %d.\n\n", price[curr], price[other]);
    }
    return 0;
}