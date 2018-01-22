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

ll convert(string& s) {
    ll ans = 0;
    if(s[0]=='0') return -1;
    for(char c : s) ans = ans*10 + (c-'0');
    return ans;
}
int main() {
    SYNC
    ll a, b, ans=0, cur=0;
    cin >> a >> b;  
    string s=to_string(a), t, x=to_string(b);
    sort(s.begin(), s.end());
    t=s;
    int ind=0;
    if(s.length() != x.length()) {
        sort(s.begin(), s.end(), greater<char>());
        cout << convert(s); return 0;
    }
    vector<ll> fac; ll tmp=1;
    FOR0(i, 20) {
        fac.pb(tmp); tmp *= 10;
    }
    while(s.length()) {
        for(char c : s) {
            if((ind || c!='0') && c<x[ind]) {
                t=s; t.erase(find(t.begin(), t.end(),c));
                sort(t.begin(), t.end(), greater<char>());
                int p = (int)s.length();
                ans=max(ans,cur*fac[p] + (c-'0')*fac[p-1] + convert(t));
            } else if(c==x[ind]) {
                cur=cur*10+(c-'0');
                s.erase(find(s.begin(), s.end(),c));
                break;
            } else if(c>x[ind]){
                s="";break;
            }
        }
        ind++;
    }
    ans=max(ans, cur);
    cout << ans;
}