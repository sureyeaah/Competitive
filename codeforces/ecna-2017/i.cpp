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
int a[4], b[4], tmp[10];
int inv() {
    FOR0(i, 4) tmp[i] = a[i];
    int ret = 0;
    FOR0(i, 4) {
        FOR(j, i, 4) {
            if(b[i] == tmp[j]) {
                FORD(k, i, j) {
                    swap(tmp[k], tmp[k+1]);
                    ret++;
                }
                break;
            }
        }
    }
    return ret;
}
string op = "+-*/";
int numIndex=0;
int replace(string& s, int st) {
    // cerr << '#' << s << endl;
    if(s[st+1] == '+') {
        tmp[numIndex] = tmp[s[st]-'0'] + tmp[s[st+2]-'0'];
    } else if(s[st+1] == '-') {
        tmp[numIndex] = tmp[s[st]-'0'] - tmp[s[st+2]-'0'];
    } else if(s[st+1] == '*') {
        tmp[numIndex] = tmp[s[st]-'0'] * tmp[s[st+2]-'0'];
    } else {
        if(tmp[s[st+2]-'0']==0 || tmp[s[st]-'0'] % tmp[s[st+2]-'0']) return 0;
        tmp[numIndex] = tmp[s[st]-'0'] / tmp[s[st+2]-'0'];
    }
    s.erase(st+1, 2);
    s[st] = (numIndex++) + '0';
    return 1;
}
int eval(string& s, int st, int nd) {
    // cerr << s << endl;
    while(nd > st) {
        // cerr << '$' << st << ' '<< nd << " string : " << s << endl;
        int found = 0;
        FOR(i, st, nd) {
            if(s[i]=='*' || s[i]=='/') {
                if(!replace(s, i-1)) return 0;
                nd -= 2;
                found = 1; break;
            }
        }
        if(!found) {
            while(nd > st) {
            // cerr << '$' << st << ' '<< nd << " string : " << s << endl;
            
            FOR(i, st, nd) {
                if(s[i]=='+' || s[i]=='-') {
                    if(!replace(s, i-1)) return 0;
                    nd -= 2;
                }
            }
            
        }   
        }
        
    }
    return 1;
}
int parse(string& s) {
    // cerr << s << endl;
    while(1) {
        int b = -1;
        FOR0(i, s.length()) {
            if(s[i]=='(') b=i;
        }
        if(b==-1) {
            return eval(s,0,s.length()-1)?tmp[numIndex-1]:-1;
        }
        FOR(i, b + 1, s.length()) {
            if(s[i]==')') {
                s.erase(i, 1);
                if(!eval(s, b+1, i-1)) return -1;
                s.erase(b, 1);
                break;
            }
            
        }
    }
    
}
bool solve(V<char>& ops, int b) {
    FOR0(b1s, 3) {
        FOR(b2s, b1s, 3) {
            FOR(b1e, b1s + 1, 4) {
                FOR(b2e, b2s + 1, 4) {
                    if(b==1 && (b1s != b2s || b1e != b2e)) continue;
                    if(!b) b1s = b2s = 0, b1e = b2e = 3;
                    FOR0(i, 4) tmp[i] = a[i];
                    string s;
                    FOR0(i, 4) {
                        if(b1s==i) s.pb('(');
                        if(b2s==i) s.pb('(');
                        s.pb(i+'0');
                        
                        if(b1e==i) s.pb(')');
                        if(b2e==i) s.pb(')');
                        if(i<3) s.pb(ops[i]);
                    }
                    numIndex = 4;
                    if(parse(s) == 24) return 1;
                    if(!b) return 0;
                }
            }
        }
    }
    return 0;
}
int main() {
    SYNC

    FOR0(i, 4) cin >> a[i];
    FOR0(i, 4) b[i] = a[i];
    sort(a, a + 4);
    int ans = inf;
    do {
        int cur = inf;
        for(char c1 : op) {
            for(char c2 : op) {
                for(char c3 : op) {
                    V<char> ops({c1, c2, c3});
                    FOR0(b, 3) {
                        if(solve(ops, b)) cur = min(cur, b);
                    }
                }
            }
        }
        ans = min(ans, cur + 2*inv());
    } while(next_permutation(a, a + 4));
    if(ans < inf) cout << ans;
    else cout << "impossible";
}