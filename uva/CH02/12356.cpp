#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int S, B, l, r, x, y;
    int nextalive[100005];
    int prevalive[100005];
    while(true) {
        cin >> S >> B;
        if(S==0 && B==0) break;
        FOR(i,0,S+2) {
            nextalive[i] = i;
            prevalive[i] = i;
        }
        while(B--) {
            l = geti(); r = geti();
            x = nextalive[r+1]; y = prevalive[l-1];
            while(x != nextalive[x]) x = nextalive[x];
            while(y != prevalive[y]) y = prevalive[y];
            nextalive[r] = nextalive[l] = x;
            prevalive[l] = prevalive[r] = y;
            if (prevalive[l] < 1) cout << "*" << " ";
            else cout << prevalive[l] << " ";
            if (nextalive[r] > S) cout << "*" << endl;
            else cout << nextalive[r] << endl; 
        }
        cout << "-" << endl;
    }
}