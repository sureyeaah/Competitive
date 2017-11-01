#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
char big[100][100], small[100][100];
int main(){
    while(true) {
        int N, n;
        cin >> N >> n; cin.ignore();
        if(!N) break;
        int a[4] = {0};
        FOR0(i,N) {
            FOR0(j, N) {
                big[i][j] = getchar();
            }
            cin.ignore();
        }
        FOR0(i,n) {
            FOR0(j, n) {
                small[i][j] = getchar();
            }
            cin.ignore();
        }
        FOR0(I, N-n+1) {
            FOR0(J, N-n+1) {
                bool yes = true;
                FOR0(i,n) {
                    FOR0(j,n) {
                        if(big[I+i][J+j] != small[i][j]) {yes = false; i = n; j = n;break;}
                    }
                }
                if(yes) a[0]++;
                yes = true;
                FOR0(i,n) {
                    FOR0(j,n) {
                        if(big[I+i][J+j] != small[n-1-j][i]) {yes = false; i = n; j = n;break;}
                    }
                }
                if(yes) a[1]++;
                yes = true;
                FOR0(i,n) {
                    FOR0(j,n) {
                        if(big[I+i][J+j] != small[n-1-i][n-1-j]) {yes = false; i = n; j = n;break;}
                    }
                }
                if(yes) a[2]++;
                yes = true;
                FOR0(i,n) {
                    FOR0(j,n) {
                        if(big[I+i][J+j] != small[j][n-1-i]) {yes = false; i = n; j = n;break;}
                    }
                }
                if(yes) a[3]++;
            }
        }
        cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
    }
}