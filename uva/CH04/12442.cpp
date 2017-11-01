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

int t,n,u,v,fwdTo[50001], reaches[50001], cycleStart = 0, cycleLength, tillHere[50001];

int dfs(int u) {
    int v = fwdTo[u];
    if(!tillHere[v]) {
        tillHere[v] = tillHere[u] + 1;
        dfs(v);
    } else if(!reaches[v]) {
        cycleStart = v;
        cycleLength = tillHere[u] - tillHere[v];
    }
    if(cycleStart){
        if(u == cycleStart) cycleStart = 0;
        return reaches[u] = cycleLength;
    }
    return reaches[u] = reaches[v] + 1;
}

int main() {
    scanf("%d", &t);
    FOR(caseNumber,1,t+1) {
        scanf("%d", &n);
        FOR0(i, n+1) {
            tillHere[i] = reaches[i] = 0;
        }
        cycleStart = cycleLength = 0;
        FOR0(i, n) {
            scanf("%d%d", &u, &v);
            fwdTo[u] = v;
        }
        int maxReach = 0, best;
        FOR(i,1,n+1) {
            if(!tillHere[i] && !reaches[i]){
                tillHere[i] = 1;
                dfs(i);
            }
        }
        printf("Case %d: %d\n", caseNumber, (int)(max_element(reaches+1, reaches+n+1) - reaches));
    }
}

/*
O(t*n*n) TLE
    int t,n,u,v,fwdTo[50001], currReach;
bool visited[50001];

void dfs(int u) {
    visited[u] = true;
    if(!visited[fwdTo[u]]) {
        dfs(fwdTo[u]);
        currReach++;
    }
    visited[u] = false;
}

int main() {
    scanf("%d", &t);
    FOR(caseNumber,1,t+1) {
        scanf("%d", &n);
        FOR0(i, n) {
            scanf("%d%d", &u, &v);
            fwdTo[u] = v;
            visited[u] = false;
        }
        int maxReach = 0, best;
        FOR(i, 1, n+1) {
            currReach = 0;
            dfs(i);
            if(currReach > maxReach) {
                best = i;
                maxReach = currReach;
            }
        }
        printf("Case %d: %d\n", caseNumber, best);
    }
}

*/