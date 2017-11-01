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
    int t, n, prevLen, currLen, present;
    string prev, curr, prevOutput, currOutput;
    char c;
    scanf("%d", &t);
    FOR(caseNumber,1,t+1) {
        scanf("%d", &n);
        while(getchar() != '\n') {}
        prevLen = -1;
        FOR0(i, n) {
            curr = "";
            currOutput = "";
            currLen = present = 0;
            while(c = getchar(), c!='\n') {
                currOutput += c;
                if(c != ' ') {
                    curr += c;
                    if(!(present & (1 << (c-'A')))) {
                        currLen++;
                        present |= 1 << (c-'A');
                    }
                }
            }
            if(currLen > prevLen) {
                prev = curr;
                prevLen = currLen;
                prevOutput = currOutput;
            } else if (currLen == prevLen && curr < prev) {
                prev = curr;
                prevOutput = currOutput;
            }
        }
        cout << "Case #" << caseNumber << ": " << prevOutput << endl;
    }
}