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

int row[9], changed[9], minimumMoves;

int countMoves() {
    int ret = 0;
    FOR(i,1,9) if(row[i] != changed[i]) ret++;
    return ret;
}

bool safe(int c) {
    FOR(i,1,c) {
        if(changed[i] == changed[c] || ABS(changed[i] - changed[c]) == (c - i)) return false;
    }
    return true;   
}

void backtrack(int k) {
    if(k == 9) minimumMoves = MIN(countMoves(), minimumMoves);
    else {
        FOR(i,1,9) {
            changed[k] = i;
            if(safe(k)) backtrack(k+1);
            changed[k] = row[k];
        }
    }
}

int main(){
    int tc = 1;
    while(cin >> row[1]) {
        FOR(i,2,9) cin >> row[i];
        minimumMoves = 9;
        backtrack(1);
        printf("Case %d: %d\n", tc, minimumMoves);
        tc++;
    }
    return 0;
}