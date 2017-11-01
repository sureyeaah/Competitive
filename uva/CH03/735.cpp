#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int score;
    bool possible[61];
    memset(possible, false, sizeof possible);
    FOR(i,1,21) {
        possible[i] = possible[2*i] = possible[3*i] = true;
    }
    possible[0] = possible[50] = true;
    while(scanf("%d", &score), score > 0) {
        int allue = 0, alle = 0, twoe = 0;
        int highest = min(score+1, 61);
        if(score > 180 or score < 0) highest = -1;
        FOR(a, 0, highest) {
            if(!possible[a]) continue;
            FOR(b, 0, highest) {
                int c = score - b - a;
                if( c < 0 || c > 60 || !possible[b] || !possible[c]) continue;
                if(a == b) {
                    if(b == c)
                        alle++;
                    else twoe++;
                }
                else if(a == c || b == c)
                    twoe++;
                else allue++;
            }
        }
        if(allue == 0 && alle == 0 && twoe == 0)
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
        else {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, allue/6 + alle + twoe/3);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, allue+alle+twoe);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
}