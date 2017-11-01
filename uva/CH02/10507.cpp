#include <iostream>
#include <string>
#include <map>
#include <vector>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if(c==EOF) return 0;if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int n, m, x, y; char a, b, c;
    while (cin >> n) {
        cin >> m;
        cin.ignore();
        bool awake[26] = {false}; vector< vector<bool> > brain(n, vector<bool>(n, false));
        map<char, int> table; int index = 0;
        FOR0(i,3) {
            c = getchar();
            table[c] = index; 
            awake[index] = true;
            index++;
        }
        int num = 3, years = 0;
        cin.ignore();
        while(m--) {
            a = getchar(); b = getchar();
            if(!table.count(a)) {table[a] = x = index; index++;} else x = table[a];
            if(!table.count(b)) {table[b] = y = index; index++;} else y = table[b];
            brain[x][y] = brain[y][x] = true;
            cin.ignore();
        }
        while(num < n) {
            bool changed = false;
            vector<bool> nextawake(n, false);
            FOR0(i, n) {
                if(!awake[i]) {
                    int numawake = 0;
                    FOR0(j,n) {
                        if(brain[i][j] && awake[j]) numawake++;
                    }
                    if(numawake >= 3) {num++; nextawake[i] = true;}
                }
            }
            FOR0(i, n) {
                if(nextawake[i]) {awake[i] = true; changed = true;}
            }
            if(!changed) {break;}
            years++;
        }
        if(num < n) cout << "THIS BRAIN NEVER WAKES UP" << endl;
        else cout << "WAKE UP IN, "<< years <<", YEARS" << endl;
    }
}