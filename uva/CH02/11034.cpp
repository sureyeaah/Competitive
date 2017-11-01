#include <iostream>
#include <queue>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int c, l, m, x; char ch;
    cin >> c;
    queue<int> cars[2];
    while(c--){
        cin >> l >> m;
        l *= 100;
        FOR0(i, m) {
            x = geti();
            ch = getchar();
            cin.ignore(6, '\n');
            if(ch == 'l') cars[0].push(x);
            else cars[1].push(x);
        }
        int cs = 0, numCrossed = 0;
        while(!cars[0].empty() || !cars[1].empty()) {
            int lenCov = 0;
            while(!cars[cs].empty() && cars[cs].front() <= l - lenCov) {
                lenCov += cars[cs].front();
                cars[cs].pop();
            }
            numCrossed++;
            cs = 1 - cs;
        }
        cout << numCrossed << endl;
    }
}