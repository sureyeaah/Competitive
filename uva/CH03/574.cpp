#include <algorithm>
#include <iostream>
#include <vector>
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
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int t, n, num, x;
int out[15] = {}, list[15] = {}, Count[110] = {}; 
bool printed, started;

void output() {
    started = false;
    printed = true;
    FOR(i, 0, num) {
        FOR0(j, out[i]){
            if(started) printf("+%d", list[i]);
            else printf("%d", list[i]);
            started = true;   
        }
    }
    printf("\n");
}

void backtrack(int k, int sum) {
    if(sum == t) output();
    else {
        FOR(i, k, num) {
            if(Count[list[i]] && sum + list[i] <= t) {
                Count[list[i]]--;
                out[i]++;
                backtrack(i, sum + list[i]);
                Count[list[i]]++;
                out[i]--;
            }
        }
    }
}


int main(){
    while(true) {
    	scanf("%d %d", &t, &n);
        if(t == 0 && n == 0) break;
        num = 0;
        memset(Count, 0, sizeof Count);
        FOR0(i, n) {
            scanf("%d", &x);
            if(Count[x] == 0) {
                list[num] = x;
                num++;
            }
            Count[x]++;
        }
        sort(list, list+num, greater<int>());
        printf("Sums of %d:\n", t);
        printed = false;
        memset(out, 0, sizeof(out));
        backtrack(0, 0);
        if(!printed) printf("NONE\n");
    }
    return 0;
}