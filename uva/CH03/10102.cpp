#include <iostream>
#include <vector>
#include <algorithm>
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
    int m;
    char x;
    string s;
    while(cin >> m) {
        int minMoves = 0;
        vii one, three;
        cin.ignore();
        FOR0(i,m) {
            getline(cin, s);
            FOR0(j, m) {
                x = s[j];
                if(x == '1') one.push_back(make_pair(i,j));
                else if(x == '3') three.push_back(make_pair(i, j));
            }
        }
        FOR0(i, one.size()) {
            int localMin = 2*(m-1);
            FOR0(j, three.size()) {
                int moves = ABS(one[i].first - three[j].first) + ABS(one[i].second - three[j].second);
                if(moves < minMoves) {
                    localMin = 0;
                    break;
                }
                else localMin = MIN(localMin, moves);
            }
            minMoves = MAX(minMoves, localMin);
        }
        cout << minMoves << endl;
    }
}