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
int cnt[10] = {}, cl = 0, cr = 0, ans = 0, lnum[20], rnum[20];
ll l, r;
cin >> l >> r;
void check(int tot) {
    int i = 1;
    while(!cnt[i]) i++;
    
}
void recurse(int prev, int tot) {
    if(tot) check(tot);
    if(tot == cr) return;
    for(int i = prev; i < 10; i++) {
        cnt[i]++;
        recurse(i, tot + 1);
        cnt[i]--;
    }
}
int getcnt(ll x, int arr[]) {
    int ret = 0;
    for(;x;x/=10) arr[ret++] = x%10;
    return ret;
}
int main() {
    SYNC
    cl = getcnt(l, lnum);
    cr = getcnt(r, rnum);
    recurse(1, 0);
}