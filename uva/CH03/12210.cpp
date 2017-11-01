
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 2000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
int main(){
    int b, s;
    int tc = 1, x;
    while(scanf("%d%d", &b, &s) && b!=0 && s!=0) {
        //set<int> spin;
        // get the ages of bachelors and the spinsters
        int minimumAge = INF;
        FOR0(i, b) {
            scanf("%d", &x);
            minimumAge = MIN(x, minimumAge);
        }
        FOR0(i, s) {
            scanf("%d", &x);    
        }
        
        if(b <= s) printf("Case %d: 0\n", tc);
        else printf("Case %d: %d %d\n", tc, b-s, minimumAge);
        tc++;
    }
    return 0;
}


// sort the bachelor array in descending order
        // greedy
        /*
        FOR0(i, b) {
            int age = bach[i];
            set<int>::iterator spinIndex = spin.lower_bound(age);
            int spinAge = *spinIndex;
            if(spinAge > age && spinIndex != spin.begin()) {
                int diff = spinAge - age;
                prev(spinIndex);
                if(age - (*spinIndex) > diff) next(spinIndex);                 
            } else if(spinAge < age && spinIndex != spin.end()) {
                int diff = age - spinAge;
                next(spinIndex);
                if((*spinIndex - age) > diff) prev(spinIndex);
            }
            spin.erase(*spinIndex); 
        }
        */