#include <iostream>
#include <map>
#include <set>
#include <vector>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
bool started = false;
vector<int> details(3);
struct det {
    bool problem[9];
    int time[9];
    int sum;
    int pus;
} temp = {{}, {}, 0, 9};
int main(){
    int n, c, p, t; char l; cin >> n; cin.ignore(); cin.ignore();
    while(n--) {
        map<int , det> rank;
        while(true) {
            string s, tmp;
            getline(cin, s);
            if(s.length() == 0) {break; if(n) cin.ignore();}
            int k = 0; 
            while(s[k] != ' ') {tmp += s[k]; k++;}
            c = stoi(tmp); k++;
            tmp = "";
            while(s[k] != ' ') {tmp += s[k]; k++;}
            p = stoi(tmp); k++;
            tmp = "";
            while(s[k] != ' ') {tmp += s[k]; k++;}
            t = stoi(tmp); k++;
            l = s[s.length()-1];

            if(!rank.count(c)) {rank[c] = temp;}
            if(!rank[c].problem[p-1]) {
                if(l=='C') {rank[c].pus--; rank[c].problem[p-1] = true; rank[c].time[p-1] += t;}
                if(l=='I') {rank[c].time[p-1] += 20;}
            }
        }
        if(started) cout << endl;
        set< vector<int> > ranklist;
        for(auto& i : rank) {
            int total = 0;
            FOR0(j,9) {
                if(i.second.problem[j]) total += i.second.time[j]; 
            }
            i.second.sum = total;
            details[0] = i.second.pus; details[1] = i.second.sum; details[2] = i.first;
            ranklist.insert(details);
        }
       for(auto i : ranklist) {
           cout << i[2] << ' ' << 9 - i[0] << ' ' << i[1] << endl;
        }
        started = true;
    }
}