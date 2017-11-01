#include <algorithm>
#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
char x,y;
bool comp(char a, char b) {
    x = tolower(a); y = tolower(b);
    if(x<y) return true;
    if(x==y) return a < b;
    return false;
}

int main(){
    string s; char c; int n;
    cin >> n; cin.ignore();
    while(n--) {
        getline(cin, s);
        sort(s.begin(), s.end(), comp);
        do{
            cout << s << "\n";
        }while(next_permutation(s.begin(),s.end(),comp));
    }
}