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
#define INF 2000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int read_int(){
	char r;
	bool start=false,neg=false;
    int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

int main() {
    int n, input[1000], m, tc = 1, query;
    while(true) {
        n = read_int();
        if(n == 0) break;
        FOR0(i, n) input[i] = read_int();
        printf("Case %d:\n", tc);
        m = read_int();
        FOR0(q,m) {
            query = read_int();
            int closestSum = input[0] + input[n-1];
            FOR0(i,n) {
                FOR0(j,n) {
                    if(i!=j && abs(closestSum - query) > abs(input[i] + input[j] - query)) closestSum = input[i] + input[j];
                }
            }
            printf("Closest sum to %d is %d.\n", query, closestSum); 
        }
        tc++;
    }
}