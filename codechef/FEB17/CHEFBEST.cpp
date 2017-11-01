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
//#define GIRL  true
//#define  BOY false
int main() {
    int t, n, x;
    int gatr[(int)1e5 + 10];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int prevB = -1, len = 0;
        FOR0(i, n) {
            scanf("%d", &x);
            if(!x) {
                if(prevB == -1) {
                    prevB = i;
                    continue;
                }
                gatr[len] = i - prevB - 1;
                prevB = i;
                len++;
            }
        }
        gatr[len] = n - 1 - prevB;
        if(gatr[len]) len++;
        int seconds = 0;
        
    }
}