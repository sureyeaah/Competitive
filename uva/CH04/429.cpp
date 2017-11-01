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

bool related(string a, string b) {
    if(a.length() != b.length()) return false;
    int numDiff = 0;
    FOR0(i, a.length()) {
        if (a[i] != b[i]) numDiff++;
    }
    return !(numDiff-1);
}

int main() {
    int n;
    bool started = false;
    string s,s1,s2;
    vector<string> words;
    vvi graph(200);
    queue<int> q;
    int changes[210];
    scanf("%d", &n);
    while(getchar() != '\n') {}
    while(getchar() != '\n') {}
    while(n--) {
        words.clear();
        while(true) {
            getline(cin, s);
            if (s[0] == '*') break;
            words.pb(s);
        }
        FOR0(i, words.size()) graph[i].clear();
        sort(words.begin(), words.end());
        FOR0(i, words.size()) {
            FOR0(j, i) {
                if(related(words[i], words[j])) {
                    graph[i].pb(j);
                    graph[j].pb(i);
                }
            }   
        }
        while(true) {
            getline(cin, s);
            if(!s.length()) break;
            istringstream iss(s);
            getline(iss, s1, ' ');
            getline(iss, s2);
            int w1 = lower_bound(words.begin(), words.end(), s1) - words.begin(), w2 = lower_bound(words.begin(), words.end(), s2) - words.begin();
            memset(changes,0,sizeof changes);
            changes[w1] = 1;
            q.push(w1);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                repi(i, graph[u]) {
                    if(!changes[*i]) {
                        changes[*i] = changes[u] + 1;
                        q.push(*i);
                    }
                }
            }
            cout << s1 << " " << s2 << " " << changes[w2] - 1 << endl; 
        }
        if(n) printf("\n");
    }   
}