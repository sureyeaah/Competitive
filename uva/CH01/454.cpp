#include <iostream>
#include <map>
#include <algorithm>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    string s, ss; int n; char c;
    cin >> n; cin.ignore(); cin.ignore();
    while(n--) {
    	int numIn = 0;
        map<string, string > m;
        while(true) {
            s = ""; ss = "";
            getline(cin, s);
            if(!s.length()) break;
            numIn++;
            FOR0(i, s.length()) {
                if(s[i] != ' ') ss = ss + s[i];
            }
            sort(ss.begin(), ss.end());
            m[s] = ss;
        }
        map<string, string>::iterator i = m.begin();
        while(numIn>1) {
            s = i->first; ss = i->second;
            map<string, string>::iterator j = i; j++;
            for(; j != m.end(); j++) {
                if(ss == j->second) {
                    cout << s << " = " << j->first << endl;
                }
            }
            i++; numIn--;
        }
        if(n) cout << endl;
    }
}