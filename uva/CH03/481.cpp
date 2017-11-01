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
vi tail, input;
bool comp(const int& x, const int &val) {
    return input[x] < input[val];
}
int main() {
    int x;
    while((scanf("%d", &x) != EOF)) {
        input.pb(x);
    }
    vi prev(input.size(), -1);
    FOR0(i, input.size()) {
        int pos = lower_bound(tail.begin(), tail.end(), i, comp) - tail.begin();
        if(pos) prev[i] = tail[pos-1];
        if(pos == tail.size()) {
            tail.pb(i);
        } else {
            tail[pos] = i;
        }
    }
    printf("%d\n-\n", tail.size());
    int k = *tail.rbegin(); vi output;
    while(k != -1) {output.pb(input[k]); k = prev[k];}
    FORD(i,0,tail.size()) printf("%d\n", output[i]);
}