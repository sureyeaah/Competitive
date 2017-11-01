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
#define B 21
#define N 300005
int cur = 0;
bitset<B> bs, kk;
int trie[N*B][2] = {}, tot = 0, cnt[N*B][2] = {};
void binary(int x, bitset<B>& bit = bs) {
    FOR0(i, B) {
        bit[B-i-1] = x&1;
        x >>= 1;
    }
}
int add(int x) {
    binary(x);
    int p = 0;
    FOR0(i, B) {
        if(!trie[p][bs[i]])
            trie[p][bs[i]] = ++tot;
        cnt[p][bs[i]]++;
        p = trie[p][bs[i]];
    }
}

int search() {
    int p = 0; int ret = 0;
    FOR0(i, B) {
        int val = kk[i];
        if(!trie[p][val]) break;
        if(cnt[p][val] < (1 << (B - i - 1))) {
            p = trie[p][val];
            // ret |= !val ? (1 << (B - i - 1)): 0;
        } else {
            val = !val;
            ret |= 1 << (B - i - 1);
            if(!trie[p][val]) {
                break;
            } else p = trie[p][val];
        }
    }
    return ret;
}

int main() {
    SYNC
    int n, m, a, x;
    cin >> n >> m;
    set<int> s;
    FOR0(i, n) {
        cin >> a;
        if(s.find(a) == s.end()) add(a);
        s.insert(a);
    }
    FOR0(i, m) {
        cin >> x;
        cur ^= x;
        binary(cur, kk);
        cout << search() << '\n';
    }
}