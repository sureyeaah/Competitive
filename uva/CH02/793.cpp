#include <iostream>
#include <string>
#include <map>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int r[10000], p[10000];

int connectTop(int x) {
    while(x != p[x]) {p[x] = p[p[x]]; x = p[x];}
    return x;
}

int main(){
    string s; char c;
    int TC, n, x, y;
    scanf("%d",&TC);
    cin.ignore();
    FOR0(tc, TC) {
        scanf("\n%d\n",&n);
        int sa = 0, ua = 0, index = 0;
        FOR(i,1,n+1) {p[i] = i; r[i] = 0;}
        while(true) {
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            p[x] = connectTop(x);
            p[y] = connectTop(y); 
            if(c == 'c') {  
                if(p[x] != p[y]) {
                    if(r[p[x]] > r[p[y]]) p[p[y]] = p[x];
                    else {
                        p[p[x]] = p[y];
                        if(r[p[x]] == r[p[y]]) {
                            r[p[y]]++;
                        }
                    }
                }
            } else if(c == 'q'){
                if(p[x] == p[y]) sa++; else ua++;
            }
        }
        if(tc) printf("\n");
        printf("%d,%d\n",sa,ua);
    }   
}