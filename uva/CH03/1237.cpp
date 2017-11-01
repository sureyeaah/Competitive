#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
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

int main() {
    int t,d,l,h,q,p;
    string s;
    vector<pair<ii, string> > m(10000);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &d);
        cin.ignore();
        FOR0(i, d) {
            getline(cin,s,' ');
            scanf("%d%d",&l, &h);
            cin.ignore();
            m[i] = make_pair(make_pair(l,h), s);
        }
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &p);
            s = "UNDETERMINED"; bool foundOne = false;
            for(auto it = m.begin(); it!=m.begin()+d; it++) {
                ii price_pair = (*it).first;
                if(price_pair.first <= p && price_pair.second >= p) {
                    if(foundOne) {
                        s = "UNDETERMINED";
                        break;
                    }
                    foundOne = true; s = (*it).second;
                }
            }
            cout << s << endl;
        }
        if(t) printf("\n");
    }
}