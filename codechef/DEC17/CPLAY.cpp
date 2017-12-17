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
#define inf ((int)1e9)
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

int main() {
    SYNC
    string s;
    while(cin >> s) {
        int x = 0, y = 0, kicks = 0, win = 0;
        FOR0(i, 5) {
            x += s[i*2]=='1';
            kicks ++;
            if(y + 5 - i < x) {
                win = 1; break;
            }
            if(x + 4 - i < y) {
                win = 2; break;
            }
            y += s[i*2 + 1]=='1';
            kicks ++;
            if(y + 4 - i < x) {
                win = 1; break;
            }
            if(x + 4 - i < y) {
                win = 2; break;
            }
        }
        if(!win) {
            FOR(i, 5, 10) {
                x += s[i*2]=='1';
                y += s[i*2 + 1]=='1';
                kicks += 2;
                if(x != y) {
                    if(x > y) win = 1;
                    else win = 2;
                    break;
                }
            }
        }
        if(win) {
            cout << (win == 1 ? "TEAM-A ": "TEAM-B ") << kicks << newl; 
        } else cout << "TIE" << newl;
    }
}