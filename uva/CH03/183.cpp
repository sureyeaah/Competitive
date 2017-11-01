#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <bitset>
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
typedef vector<vi> vvi;

int main() {
    char type;
    string s;
    string::size_type ptr;
    int n, m;
    char decomposed[40000], type;
    bitset<200> b[200];
    getline(cin, s);
    type = s[0];
    while(type != '#') {
        s = s.substr(1);
        n = stoi(s, &ptr);
        m = stoi(s.substr(ptr), nullptr);
        if(type == 'B') {
            do {
                getline(cin, s);
                
            }
            while(s[0] == '0' || s[0] == '1')
        else {
            
        }
    }
    
}