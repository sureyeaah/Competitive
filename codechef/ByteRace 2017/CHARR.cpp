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

int t,n,a[100000 + 10], reaches[100000 + 10], cycleStart = 0, cycleLength, tillHere[100000 + 10];
bool inCycle[100000 + 10];
int dfs(int u) {
    int v = a[u];
    if(v == a[v]) {
        return reaches[u] = 1;
    }
    if(!tillHere[v]) {
        tillHere[v] = tillHere[u] + 1;
        dfs(v);
    } else if(!reaches[v]) {
        cycleStart = v;
        cycleLength = tillHere[u] - tillHere[v];
    }
    if(cycleStart){
        inCycle[u] = true;
        if(u == cycleStart) cycleStart = 0;
        return reaches[u] = cycleLength;
    }
    return reaches[u] = reaches[v] + 1;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        FOR0(i, n+1) {
            tillHere[i] = reaches[i] = 0;
            inCycle[i] = false;
        }
        cycleStart = cycleLength = 0;
        FOR0(i, n) scanf("%d", a + i + 1);
        FOR(i,1,n+1) {
            if(!tillHere[i] && !reaches[i]){
                tillHere[i] = 1;
                dfs(i);
            }
        }
        FOR(i,1,n+1) if(inCycle[i]) reaches[i]++;
        cout << (int)(*max_element(reaches+1, reaches+n+1)) << endl;
    }
}
