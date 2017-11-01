#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int a[2*n], n, s;
bitset<2*n> used;
string s = "";
void check() {
    int sum = -1, st = 0;
    FOR0(i, 5) {
        int cur = a[i] + a[i+5] + a[(i + 1) % 5 + 5];
        if(a[i] < a[st]) st = i;
        if(sum == -1) sum = cur;
        else if(sum != cur) return;
    }
    string out = "";
    FOR0(j, 5) {
        int i = (j + st) % 5;
        out +=  to_string(a[i]) + to_string(a[i+5]) + to_string(a[(i + 1) % 5 + 5]);
    }
    if(out > s) s = out;
}
void backtrack(int k) {
    if(k == n) {
        check();
        return;
    }
    FOR0(i,10) if(!used[i]) {
        a[k] = i;
        used[i] = 1;
        backtrack(k+1);
        used[i] = 0;
    }
}

int main() {
    SYNC
    cin >> n >> s;
    backtrack(0);
    for(auto& ans : s) cout << ans << "\n";
}