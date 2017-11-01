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
    unsigned long long int a, b, c, d, mod = 1000000007, n2, n1;
    long long int n;
    cin >> a >> b >> n1 >> n2 >> n;
    int num = (n%2 == 0) ? n-2: n-1;
    for(int i = 1; i <= num; i+=2) {
        c = ((n1*((a*n1)%mod + b)%mod)%mod + (a*n2)%mod ) % mod;
        d = (n2*((a*n1)%mod + b)%mod) % mod;
        a = c; b = d;
    }
    if(n%2 != 0) cout << a << endl;
    else cout << (n2*((a*n1)%mod + b)%mod) % mod << endl;
    return 0;
}