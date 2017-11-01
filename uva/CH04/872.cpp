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

int cases, n, ctoi[26], indeg[26], level[26], component[26], numComp, levels;
char itoc[26];
string input, output;
vvi graph(26);
vector<vector<vector<char> > > order(26, vector<vector<char> >(26)); // [component][level][member]

void print() {
    FOR0(i, output.length() - 1) printf("%c ", output[i]);
    printf("%c\n", output[output.length() - 1]);
}

int compBool;
void gen(int comp, int lv, int len) {
    if(len == n) {
        print();
        return;
    }
    if(len == 0) {output = ""; compBool = 0;}
    compBool |= (i << comp);
    FOR
}

int main() {
    
    scanf("%d", &cases);
    while(getchar() != '\n') {}
    while(getchar() != '\n') {}
    while(cases--) {
        // get variable names
        getline(cin, input);
        n = 0;
        FOR0(i, input.length()) {
            if(input[i] >= 'A' && input[i] <= 'Z') {
                ctoi[input[i] - 'A'] = n;
                itoc[n] = input[i];
            }
        }
        FOR0(i, n) graph[i].clear(); // clear the graph
        // get the relations
        getline(cin, input);
        FOR0(i, input.length()) {
            if(input[i] >= 'A' && input[i] <= 'Z') {
                graph[ctoi[input[i] - 'A']].pb(ctoi[input[i+2] - 'A']);
                indeg[ctoi[input[i+2] - 'A']]++;
                i += 2;
            }   
        }
        memset(indeg, 0, sizeof indeg);
        bool possible = true;
        queue<int> zero;
        numComp = 0;
        FOR0(i, n) {
            if(indeg[i]) level[i] = -1;
            else level[i] = 0;
            zero.push(i);
            component[i] = numComp;
            numComp++;
        }
        while(!zero.empty()) {
            int u = zero.front(); zero.pop();
            repi(v, graph[u]) {
                indeg[*v]--;
                if(!indeg[*v]) {
                    level[*v] = level[u] + 1;
                    zero.push(*v);
                    component[*v] = component[u];
                }
            }
        }
        levels = 0;
        FOR0(i, n) {
            if(level[i] == -1) {possible = false; break;}
            levels = max(levels, level[i]); 
        }
        levels++;
        if(possible) {
            // clear the order
            FOR0(i, numComp) {
                FOR0(j, levels) {
                    order[i][j].clear();
                }
            }
            // generate basic order
            FOR0(i, n) {
                order[component[i]][level[i]].pb(itoc[i]);
            }
            FOR0(i, numComp) {
                FOR0(j, levels) {
                    sort(order[i][j].start(), order[i][j].end());
                }
            }
            FOR0(i, numComp) gen(i, 0, 0);
        } else cout << "NO" << endl;
    }
}