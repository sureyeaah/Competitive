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

int s, d, maxSurplus, a[13];

void backtrack(int k, int sum) {
    if(k <= 4) {
        a[k] = s;
        backtrack(k+1, sum+s);
        a[k] = -d;
        backtrack(k+1, sum-d);
    } else if(k <= 12) {
        if(sum + s - a[k-5] < 0) {
            a[k] = s;
            backtrack(k+1, sum + s - a[k-5]);
        } else if(sum - d - a[k-5] < 0) {
            a[k] = -d;
            backtrack(k+1, sum - d - a[k-5]);
        }
    } else {
        int sumTotal = 0;
        FOR(i,1,13) sumTotal += a[i];
        maxSurplus = max(maxSurplus, sumTotal);
    }
}

int main(){
    a[0] = 0;
    while(cin >> s) {
        cin >> d;
        maxSurplus = 0;
        backtrack(1, 0);
        if(maxSurplus > 0) cout << maxSurplus << endl;
        else cout << "Deficit" << endl;
    }
    return 0;
}