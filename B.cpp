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
#define NOT(x) (51 - x)
int b[3], n, ans[60], cnt[60], player[60], p[60], q[60][2];
char x, y;
bool valid(int i, int val) {
    return (ans[i] == -1 || ans[i] == val);
}
int findSet(int x) {
    return (x == p[x]) ? x : (p[x] = findSet(p[x]));
}
bool sameSet(int x, int y) {
    return findSet(x) == findSet(y);
}
int unite(int x, int y) {
    int px = findSet(x), py = findSet(y);
    if(px == py) return 1;
    if(ans[px] != -1 && ans[py] != -1 && ans[px] != ans[py]) return 0;
    ans[px] = ans[py] = max(ans[px], ans[py]);
    p[px] = py;
    return 1;
}
bool black(int x) {
    return find(b, b + 3, x) - b != 3;
}

int solve() {
    memset(ans, -1, sizeof ans);
    FOR0(i, 60) p[i] = i;
    bitset<60> done;
    FOR0(i, n) {
        if(black(q[i][0]) || black(q[i][1])) {
            if(black(q[i][0]) && black(q[i][1])) {
                if(cnt[i]) return 0; 
            } else {
                if(cnt[i] == 2) return 0; 
                int check = black(q[i][0]) ? q[i][1] : q[i][0];
                int cur = player[i] ^ (!cnt[i]);
                if(valid(check, cur)) {
                    ans[check] = cur;
                    ans[NOT(check)] = !cur;        
                }
                else return 0;
            }
            done[i] = 1;
        }
    }
    FOR0(i, n) {
        if(done[i] || cnt[i] == 1) continue;
        int cur = player[i] ^ (!cnt[i]);
        if(valid(q[i][0], cur) && valid(q[i][1], cur)) {
            ans[q[i][0]] = ans[q[i][1]] = cur;
            ans[NOT(q[i][0])] = ans[NOT(q[i][1])] = !cur;
        } else return 0;
        done[i] = 1;
    }
    FOR0(i, n) {
        if(done[i]) continue;
        if(!unite(q[i][0], q[i][1])) return 0;
        if(!unite(NOT(q[i][0]), NOT(q[i][1]))) return 0;
    }
    FOR0(i, 26) if(ans[findSet(i)]!= - 1 && ans[findSet(i)] == ans[findSet(NOT(i))]) return 0;
    return 1;
}
int main() {
    SYNC
    int ans = 0;
    cin >> n;
    FOR0(i, n) {
        cin >> x >> y >> player[i] >> cnt[i];
        q[i][0] = x-'A'; q[i][1] = y - 'A';
        player[i]--;
    }
    for(b[0] = 0; b[0] < 26; b[0]++) {
        for(b[1] = b[0] + 1; b[1] < 26; b[1]++) {
            for(b[2] = b[1] + 1; b[2] < 26; b[2]++) {
                ans += solve();
            }
        }
    }
    cout << ans;
}