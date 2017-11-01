#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if(c == EOF) break;if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int t, n, x, fi;
    scanf("%d", &t);
    int *array = new int[1000001];
    while(t--) {
        map<int, int> m;
        int size = 0, index = 0, s1 = 0;
        n = geti();
        FOR0(i,n) {
            array[index] = geti();
            if(m.find(array[index]) != m.end()) {
                x = m[array[index]];
                if(x >= s1) {
                    size = MAX(size, index - s1);
                    s1 = x + 1;
                }
            }
            m[array[index]] = index;
            index++;
        }
        size = MAX(size, n - s1);
        cout << size << endl;
    }
}