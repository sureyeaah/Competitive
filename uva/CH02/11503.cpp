#include <iostream>
#include <map>
#include <vector>
using namespace std;
int geti() {char c;int ret = 0;bool start = false;while(true) {c = getchar();if((c- '0' < 0 || c- '0' > 9) && !start){continue;}if((c-'0' < 0 || c -'0' > 9) && start){break;}if(start) ret *= 10;start = true;ret += c-'0';}return ret;}
vector<int> root;
int findRoot(int x) {
    while(x != root [x]) {root[x] = root[root[x]];x = root[x];}  
    return x;
}
int main(){
    int tc, f, x, y;string s1, s2; char c;
    tc = geti();
    while(tc--) {
        vector<int> sz; map<string, int> name; root.clear();
        int fi = 0; //index of friend for name to int map
        f = geti();
        while(f--) {
            s1 = s2 = "";
            while(c = getchar(), c!=' ') s1 += c;
            while(c = getchar(), c!='\n') s2 += c;
            if(name.find(s1) == name.end()) {name[s1] = fi; root.push_back(fi); sz.push_back(1); fi++;}
            if(name.find(s2) == name.end()) {name[s2] = fi; root.push_back(fi); sz.push_back(1); fi++;}
            x = name[s1]; y = name[s2];
            root[x] = findRoot(x); root[y] = findRoot(y);
            if(root[x] == root[y]) { printf("%d\n", sz[root[x]]);}
            else {
                if(sz[root[x]] < sz[root[y]]) {sz[root[y]] += sz[root[x]]; root[root[x]] = root[y];printf("%d\n", sz[root[y]]);}
                else {sz[root[x]] += sz[root[y]]; root[root[y]] = root[x]; printf("%d\n", sz[root[x]]);}
            }
        }
    }
    return 0;
}