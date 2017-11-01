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
#define maxn 100005
int n,k,a[maxn],geven[5] = {0,1,2,0,1},godd[5] = {0,1,0,1,2};
int g(int x) {
    if(x < 5) return godd[x];
    else if (x % 2) return 0;
    else {
        bitset<3> bs;
        bs[g(x-1)] = 1;
        bs[g(x/2)] = 1;
        int ret = 0;
        while(bs[ret]) ret++;
        return ret;
    }
}
int main() {
    SYNC
    cin >> n >> k;
    FOR0(i, n) cin >> a[i];
    int ans = 0;
    if(k%2 == 0) {
        FOR0(i, n) ans ^= (a[i] < 5 ? geven[a[i]]: !(a[i]%2));
    }
    else {
        FOR0(i, n) ans ^= g(a[i]);
    }
    cout << (ans ? "Kevin": "Nicky") << endl;
}