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
ll goup(ll n) {
    string s = to_string(n);
    int i = 0, len = s.length();
    while(i < len && (((s[i]-'0') & 1) == 0)) i++;
    if(i < len && s[i] == '9') {
        FORD(j, 0, i) {
            if(s[j] != '8') {
                s[j] += 2; 
                FOR(k, j+1, len) s[k] = '0';
                break;
            } else if (!j) {
                FOR(k, 0, len) s[k] = '0';
                s = "2" + s;
            }
        }
        if (!i) {
            FOR(k, 0, len) s[k] = '0';
            s = "2" + s;
        }
        return stoll(s,nullptr,10);
    } else if(i < len) {
        s[i] += 1;
        FOR(j, i+1, len) s[j] = '0';
        return stoll(s,nullptr,10);
    } else return n;
}
ll godown(ll n) {
    string s = to_string(n);
    int i = 0, len = s.length();
    while(i < len && (((s[i]-'0') & 1) == 0)) i++;
    if(i < len) {
        s[i]--;
        FOR(k, i+1, len) s[k] = '8';
    }
    return stoll(s, nullptr, 10);
}
int main() {
    SYNC
    int t; ll n, ans;
    cin >> t;
    FOR(caseNum, 1, t + 1) {
        cin >> n;
        if(n<=1) ans = 2-n;
        else ans = min(goup(n) - n, n - godown(n));
        cout << printCase() << ans << endl;
    }
}