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
#define mod 7 + (int)1e9
int main() {
    SYNC
    int n, a, cnt[N] = {}; ll subsets[N] = {}; 
    cin >> n;
    FOR0(i, n) {
        cin >> a;
        cnt[a]++;
    }
    FORD(i,2,N) {
        int sub = 0, add = cnt[i];
        for(int j = 2; j*i < N; j++) {
            add = (add + cnt[j*i]) % mod;
            sub += subsets[j*i];
        }
        subsets[i] = (1 << add) - 1 - sub;
    }
    ll ans = 0;
    FOR(i,2,N) {
        ans += (subsets[i]*i)%mod;
        ans %= mod;
    }
    cout << ans;
}