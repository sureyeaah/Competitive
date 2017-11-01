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

int n, tracks, duration[20], c[20], out[20], out_sum, out_len;

void backtrack(int k, int sum, int c_len) {
    FOR(i, k, tracks) {
        if(sum + duration[i] <= n) {
            c[c_len] = duration[i];
            backtrack(1 + i, sum + duration[i], c_len+1);
        } else if(sum > out_sum || (sum==out_sum && c_len > out_len)){
            out_len = c_len;
            out_sum = sum;
            FOR0(j, out_len) out[j] = c[j];
        }
    }
    if(k == tracks) {
        if(sum > out_sum || (sum==out_sum && c_len > out_len)){
            out_len = c_len;
            out_sum = sum;
            FOR0(j, out_len) out[j] = c[j];
        }
    }
}

int main(){
    while(cin >> n) {
        cin >> tracks;
        FOR0(i, tracks) scanf("%d", duration + i);
        sort(duration, duration + tracks);
        out_len = out_sum = 0;
        backtrack(0, 0, 0);
        FOR0(i, out_len) printf("%d ", out[i]);
        printf("sum:%d\n", out_sum);
    }
    return 0;
}