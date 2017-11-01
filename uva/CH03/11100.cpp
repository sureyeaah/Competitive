#include <algorithm>
#include <map>
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
    // ios_base::sync_with_stdio(0);
    int n, x;
    while(scanf("%d", &n) && n != 0) {
        int k;
        map<int, int> sizes;
        while(n--) {
            scanf("%d", &x);
            if(sizes.find(x) == sizes.end()) sizes[x] = 1;
            else sizes[x]++;
        }
        int maxLen = 0;
        for(auto i = sizes.begin(); i != sizes.end(); i++) {
            maxLen = MAX(maxLen, i->second);
        }
        // sort(sizes.begin(), sizes.end());
        vector<string> out(maxLen, "");
        int prevLen = 0;
        for(auto i = sizes.begin(); i != sizes.end(); i++) {
               int len = i->second;
               string toAppend = to_string(i->first) + " ";
               int currLen = MIN(maxLen, prevLen + len);
               FOR(i, prevLen, currLen) out[i] += toAppend;
               if(currLen == maxLen) {
                   prevLen += len - maxLen;
                   FOR0(i, prevLen) out[i] += toAppend;
               }
               else prevLen = currLen;

        }
        printf("%d\n", maxLen);
        FOR0(i, maxLen){
            out[i].pop_back();
            cout << out[i] << endl;
            //printf("%s\n", out[i]);
        }
    }
    return 0;
}