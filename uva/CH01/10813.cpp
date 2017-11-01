#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int n, x, c[5][5]; c[2][2] = 100;
    cin >> n;
    while(n--) {
        bool cb[5][5] = {}, bingo = false; cb[2][2] = true;
        FOR0(i,2){
            FOR0(j,5) {
                cin >> c[i][j];
            }
        }
        cin >> c[2][0]>>c[2][1]>>c[2][3]>>c[2][4];
        FOR(i,3,5){
            FOR0(j,5) {
               cin >> c[i][j];
            }
        }
        // get balls
        int ball = 0;
        for(; ball < 75; ball++) {
            cin >> x; int col = (x-1)/15;
            FOR0(i,5) {
                if(x == c[i][col]) {
                    cb[i][col] = true;
                    bingo = true; FOR0(j,5) {if(!cb[j][col]) {bingo = false; break;} }
                    if(!bingo){bingo = true; FOR0(j,5) {if(!cb[i][j]) {bingo = false; break;} }}
                    if(!bingo) {
                            if(i == col) {bingo = true; FOR0(j,5){ if(!cb[j][j]) {bingo = false; break;}}} 
                            else if(i == 4-col) {bingo = true; FOR0(j,5){if(!cb[j][4-j]) {bingo = false; break;}}}
                    }
                    break;
                }
            }
            if(bingo) {
                ball++;
                printf("BINGO after %d numbers announced\n", ball);
                break;
            }
        }
        //left overs
        for(; ball < 75; ball++) {
                cin >> x;
        }
    }
}