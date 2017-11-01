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
#define N 1000005
char seq[N];
int p;
void recurse(int a, int b) {
    if(!b || (!a && b > 1)) {
        p = INF;
        return;
    }
    if (a == 1) {
        seq[p++] = '(';
        while(--b > 0)
            seq[p++] = ')';
        return;
    }
    if (b == 1) {
        while(a-- > 0)
            seq[p++] = '(';
        return;
    }
    if(a < b) {
        recurse(a, b - a);
        if(p != INF) seq[p++] = ')';
    }
    else {
        recurse(a - b, b);
        if(p != INF) seq[p++] = '(';
    }
}
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int calc(int a, int b) {
    if(a == 1) return b;
    if(b == 1) return a;
    if(a > b) swap(a, b);
    return calc(a, b%a) + b/a;
}
int main() {
    SYNC
    int t, x;
    cin >> t;
    while(t--) {
        cin >> x;
        int ans = INF, target;
        FOR(a, 1, x+1) {
            if(gcd(a, x + 1) > 1) continue;
            int y = calc(a, x + 1);
            if (y < ans) {
                ans = y;
                target = a;
            }
        }
        // DEBUG(ans);
        p = 0;
        recurse(target, x + 1);
        FOR0(i, ans) cout << seq[i];
        cout << endl;
    }
}