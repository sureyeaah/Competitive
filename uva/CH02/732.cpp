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
int l;
char ans[10000],s[10000],d[10000];
void print() {
    printf("%c", ans[0]);
    FOR(i,1,2*l) printf(" %c", ans[i]);
    printf("\n");
}
void backtrack(int i, int o, string curr) {
    if(i == l && o == l) print();
    if(i<l) {
        ans[i+o] = 'i';
        backtrack(i+1,o,curr+s[i]);
    }
    if(o<i) {
        ans[i+o] = 'o';
        if(curr[curr.length()-1]==d[o]) backtrack(i,o+1,curr.substr(0,curr.length()-1));
    }
}
int main() {
    while(scanf("%s",s)!=EOF) {
        scanf("%s",d);
        l = strlen(s);
        printf("[\n");
        if(l == strlen(d)) backtrack(0,0,"");
        printf("]\n");
    }
}