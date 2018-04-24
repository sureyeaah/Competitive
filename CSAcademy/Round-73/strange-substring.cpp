// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);
const int N = 2e5 + 5;
string s, x; int n, m;
int ra[N], sa[N], tmpra[N], tmpsa[N], c[N], lcp[N], dwn[N], up[N];
ll ans = 0;
void cntsort(int k) {
    int mx = max(150, n);
    memset(c, 0, sizeof c);
    FOR0(i, n) c[i + k < n ? ra[i+k]: 0]++;
    for(int i = 0, sum = 0, t; i < mx; i++) 
        t = c[i], c[i] = sum, sum += t;
    FOR0(i, n) {
        tmpsa[c[sa[i]+k < n ? ra[sa[i]+k]: 0]++] = sa[i];
    }
    FOR0(i, n) sa[i] = tmpsa[i];
}
void suffarray() {
    FOR0(i, n) sa[i] = i;
    FOR0(i, n) ra[i] = s[i];
    int k, r;
    for(k = 1; k < n; k <<= 1) {
        cntsort(k);
        cntsort(0);
        tmpra[sa[0]] = r = 0;
        FOR(i, 1, n) {
            tmpra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
            ? r: ++r;
        }
        FOR0(i, n) ra[i] = tmpra[i];
        if(ra[sa[n-1]] == n-1) break;
    }

    // lcp array
    k = 0;
    FOR0(i, n) {
        if(ra[i]==n-1) {
            k=0;
            continue;
        }
        int j = sa[ra[i] + 1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[ra[i]]=k;
        if(k) k--;
    }
    FORD(i, 0, n) {
        if(sa[i] >= m) continue;
        int len = m-sa[i];
        if(lcp[i]==0) {
            dwn[i] = 0;
            ans += len - lcp[i-1];
        }
        else {
            if(sa[i+1] >= m) dwn[i] = lcp[i];
            else dwn[i] = lcp[i] <= dwn[i+1] ? lcp[i]: dwn[i+1];
            ans += len - max(lcp[i-1], dwn[i]);
        }
    }
}
int main() {
    SYNC
    cin >> s >> x;
    m = s.length();
    s.pb('$');
    s += x;
    s.pb('#'); 
    n = s.length();
    suffarray();
    // FOR0(i, n) cout << lcp[i] << " " << dwn[i] << " " << s.substr(sa[i], n-sa[i]) << endl;
    cout << ans;
}