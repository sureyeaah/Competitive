#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
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
    int t,h,s,x,y,z,dp[2][410];
    string input;
    scanf("%d", &t);
    FOR(case_number, 1, t+1) {
        double maxprob = 0.0;
        scanf("%d%d", &h, &s);
        cin.ignore();
        FOR0(i, s) {
            if(i != s-1) getline(cin, input, ' ');
            else getline(cin, input);
            string::size_type sz;
            x = stoi(input, &sz);
            input = input.substr(sz);
            input[0] = '0';
            y = stoi(input, &sz);
            input = input.substr(sz);
            if(input.length()) {
                z = stoi(input, &sz);
            } else z = 0;
            int damage = h - z;
            ll cases = 0;
            int curr = 1;
            if(damage < x) maxprob = 1;
            else if (damage > x*y) cases = 0;
            else {
                FOR0(temp1, x*y+1) dp[0][temp1] = 0; FOR0(temp1, x*y+1) dp[1][temp1] = 0;
                dp[0][0] = 1;
                FOR(dices, 1, x+1) {
                    int maxoutcome = dices * y;
                    FOR0(temp1, maxoutcome+1) dp[curr][temp1] = 0;
                    FOR(total, dices, maxoutcome+1) {
                        FOR(outcome, 1, MIN(y, total)+1) {
                            dp[curr][total] += dp[1-curr][total - outcome];
                        }
                    }
                    curr = 1 - curr;
                }
                FOR(outcome, damage, x*y+1) cases += dp[1-curr][outcome];
            }
            maxprob = MAX(maxprob, (double)cases/(double)(pow((ll)y,(ll)x)));
        }
        printf("Case #%d: %.6f\n", case_number, maxprob);
    }
}