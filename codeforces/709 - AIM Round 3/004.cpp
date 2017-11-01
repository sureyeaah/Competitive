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
int solve(int x) {
    FOR0(i, 50000) {
        if((1LL * i * (i - 1)) == 2*x) return i;
    }
    return -1;
}
int a00, a01, a10, a11;
bool poss(int a, int b) {
    if(a == -1 || b == -1 || 1LL*a*b != a01 + a10) {
        // cout << "Impossible";
        return 0;
    }
    int cur = a, cnt[100000] = {};
    while(a01 && cur) {
        cnt[cur] = a01/cur;
        a01 -= cnt[cur]*cur;
        b-= cnt[cur--];
    }
    cnt[0] = b;
    if(cnt[0] < 0) {
        // cout << "Impossible";
        return 0;
    }
    vector<char> out;
    FOR0(i, a + 1) {
        FOR0(j, cnt[i]) out.pb('1');
        if(i != a) out.pb('0');
    }
    if(out.size() == 0) out.pb('0');
    for(char o : out) cout << o;
    return 1;
}
int main() {
    SYNC
    cin >> a00 >> a01 >> a10 >> a11;
    int a = solve(a00), b = solve(a11);
    if(poss(a, b)) return 0;
    if(!a) {
        if (poss(1, b)) return 0;
    }
    if(!b) {
        if (poss(a, 1)) return 0;
    }
    if(!a && !b) {
        if(poss(1,1)) return 0;
    }
    cout << "Impossible";
}