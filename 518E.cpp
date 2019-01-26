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
#define EPS (1e-9)
#define PI 3.1415926535
#define inf ((int)2e9)
#define INF ((ll)9e18)
#define mod (1000000000 + 7)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 1e5 + 5;
int k, n, a[N];
ll brute(int neg, int pos, int st) {
    ll ret = 0;
    if(neg >= 0 && st <= a[neg]) return INF;
    for(int j = neg + k; j < pos; j+=k) {
        ret += abs(st);
        st++;
    }
    if(pos < n && st > a[pos]) ret = INF;
    return ret;
}
int main() {
    SYNC
    string s;
    cin >> n >> k;
    FOR0(i, n) {
        cin >> s;
        if(s[0] == '?') {
            a[i] = inf;
        } else {
            istringstream iss(s);
            iss >> a[i];
        }
    }
    int ans = 1;
    FOR0(i, k) {
        int neg = i - k, pos = i + k * ((n - i - 1) / k + 1);
        for(int j = i; j < n; j+=k) {
            if(a[j] != inf) {
                if(a[j] <= 0) neg = j;
                if(a[j] >= 0) pos = min(pos, j);
            }
        }
        for(int j = neg-k; j >= i; j-=k) {
            if(a[j] == inf) {
                a[j] = a[j+k] - 1;
            } else if(a[j] >= a[j+k]) ans = 0;
        }
        for(int j = pos+k; j < n; j+=k) {
            if(a[j] == inf) {
                a[j] = a[j-k] + 1;
            } else if(a[j] <= a[j-k]) ans = 0;
        }
        int l = (pos - neg) / k - 1;
        if(l < 0) continue;
        set<pair<ll, int>> s;
        s.insert(mp(brute(neg ,pos, -l/2), -l/2));
        if(neg >= 0) s.insert(mp(brute(neg ,pos, a[neg] + 1), a[neg] + 1));
        if(pos < n) s.insert(mp(brute(neg ,pos, a[pos] - l), a[pos] - l));
        ll st;
        if((*(s.begin())).ff < inf) st = (*(s.begin())).ss;
        else ans = 0;
        for(int j = neg + k; j < pos; j+=k) {
            a[j] = st++;
        }
    }
    if(!ans) {
        cout << "Incorrect sequence";
    } else {
        FOR0(i, n) cout << a[i] << " ";
    }
}