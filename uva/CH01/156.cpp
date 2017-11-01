#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
using namespace std;
int main(){
    string s, ss; int n; char c; set<string> answer;
    	int numIn = 0;
        map<string, string > m;
        while(true) {
            s = ""; ss = "";
            while(c=getchar(), c!=' ' && c!='\n') {
                s+=c;
            }
            if(s[0] == '#') break;
            if(!s.length()) continue;
            numIn++;
            FOR0(i, s.length()) {
                ss += tolower(s[i]);
            }
            sort(ss.begin(), ss.end());
            if(!m.count(ss)) {
                m[ss] = s;
            } else {
                m[ss]= "";
            }
        }
        for(map<string, string>::iterator i = m.begin(); i != m.end(); i++) {
            if(i->second.length()) {
                answer.insert(i->second);
            }
        }
        for(set<string>::iterator i = answer.begin(); i != answer.end(); i++) {
            cout << *i << endl;
        }

}