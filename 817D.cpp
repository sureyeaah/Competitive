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
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define maxn 1000005
int n, a[maxn], len1[maxn], len2[maxn], len3[maxn], len4[maxn];
void longest(int len[]) {
    stack<int> s;
    FOR0(i, n) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        len[i] = s.empty() ? i+1 : i-s.top();
        s.push(i);
    }
}
void longest2(int len[]) {
    stack<int> s;
    FOR0(i, n) {
        while(!s.empty() && a[s.top()] > a[i]) s.pop();
        len[i] = s.empty() ? i+1 : i-s.top();
        s.push(i);
    }
}
ll solve(int lena[], int lenb[]) {
    ll ret = 0;
    longest(lena);
    reverse(a, a+n);
    longest2(lenb);
    reverse(a, a+n);
    reverse(lenb, lenb+n);
}
int main() {
    SYNC;
    cin >> n;
    FOR0(i, n) cin >> a[i];
    solve(len1, len2);
    FOR0(i, n) a[i] = -a[i];
    solve(len3, len4);
    ll ans = 0;
    FOR0(i, n) ans += (ll)a[i]*((len1[i])*((ll)len2[i]) - (len3[i])*((ll)len4[i]));
    cout << ans << endl;
}