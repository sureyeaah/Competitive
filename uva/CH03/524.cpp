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
int primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool isPrime[33] = {false};
int n;
int out[16];
int used[17] = {false};
vector<int> corresPrime[17];
void output() {
    FOR0(i, n-1) printf("%d ", out[i]);
    printf("%d\n", out[n-1]);
}

void backtrack(int k) {
    if(k == n && isPrime[out[n-1] + out[0]]) output();
    FOR0(i, corresPrime[out[k-1]].size()) {
        int j = corresPrime[out[k-1]][i];  
        if(!used[j] && j <= n) {
            used[j] = true;
            out[k] = j;
            backtrack(k+1);
            used[j] = false;
        }
    }
}

int main(){
    out[0] = 1; used[1] = true;
    // generate primes
    FOR0(i, 11) isPrime[primes[i]] = true;
    FOR(i, 1, 17) {
        FOR(j, 1, 17) {
            if(isPrime[i+j]) corresPrime[i].push_back(j);
        }
    }
    int tc = 0;
    bool started = false;
    while(cin >> n) {
        if(started) printf("\n");
        tc++;
        printf("Case %d:\n", tc);
        backtrack(1);
        started = true;
    }
    return 0;
}