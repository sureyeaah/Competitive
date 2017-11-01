#include <iostream>
#include <set>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
// int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    int bf, sg, sb, n, x, y, z;
    int array1[100000], array2[100000];
    cin >> n;
    while(n--) {
        multiset<int, greater<int> > g,b;
        cin >> bf >> sg >> sb;
        while(sg--) {
            cin >> x;
            g.insert(x);
        }
        while(sb--) {
            cin >> x;
            b.insert(x);
        }
        bf = MIN(bf,MIN(g.size(), b.size()));
        while(bf > 0) {
            int l1 = 0, l2 = 0;
            FOR0(BF,bf) {
                y = *(g.begin()); z = *(b.begin());
                g.erase(g.begin());
                b.erase(b.begin());
                if(y < z) {
                    array1[l1] = z-y;
                    l1++;
                } else if(y > z) {
                    array2[l2] = y-z;
                    l2++;
                }
            }
            b.insert(array1, array1+l1); g.insert(array2, array2+l2);
            bf = MIN(bf,MIN(g.size(), b.size()));
        }
        if(g.size()==0 && b.size()==0) {
            cout << "green and blue died\n";
        } else if(g.size()==0) {
            cout << "blue wins" << endl;
            for(set<int>::iterator it = b.begin(); it !=b.end(); it++) cout << *it << endl;
        } else {
            cout << "green wins" << endl;
            for(set<int>::iterator it = g.begin(); it !=g.end(); it++) cout << *it << endl;
        }
        if(n) cout << endl;
    }
}