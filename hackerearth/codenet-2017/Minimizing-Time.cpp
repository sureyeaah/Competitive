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
const int N = 1e5 + 5;
unordered_map<char, int> m;
string s;
int keyboard[63], a[N];
char chars[63];
unordered_map<string, int> subcnt;
int main() {
    SYNC
    srand(time(0));
    int cnt = 0;
    FOR0(i, 26) 
        m[(char)('a' + i)] = cnt++;
    FOR0(i, 26)
        m[(char)('A' + i)] = cnt++;
    FOR0(i, 10)
        m[(char)('0' + i)] = cnt++;
    m[' '] = cnt++;
    for(auto cur : m)
        chars[cur.ss] = cur.ff;
    chars[62] = '.';
    getline(cin, s);
    FOR0(i, s.length()-1) {
        subcnt[s.substr(i, 2)]++;
    }
    int bestcnt = -1; string freq;
    for(auto cur : subcnt) {
        if(cur.ss > bestcnt && cur.ff[0] != cur.ff[1]) {
            bestcnt = cur.ss;
            freq = cur.ff;
        }
    }
    FOR0(i, s.length()) a[i] = m[s[i]];
    FOR0(i, 63) keyboard[i] = i;
    int ans = 2e9, anskeyboard[63], r[63], c[63];

    FOR0(i, 6000) {
        random_shuffle(keyboard, keyboard + 63);
        FOR0(i, 63) {
            r[keyboard[i]] = i/21;
            c[keyboard[i]] = i % 21;
        }
        int cur = 0;
        FOR0(i, s.length()-1) {
            cur += abs(r[a[i]] - r[a[i+1]]) + abs(c[a[i]] - c[a[i+1]]);
            }
        if(cur < ans) {
            ans = cur;
            FOR0(i, 63) {
                anskeyboard[i] = keyboard[i];
            }
        }
    }
    FOR0(i, 63) {
        keyboard[i] = anskeyboard[i];
    }
    if(bestcnt != -1) {
        FOR0(i, 63) {
            if(m[freq[0]] == keyboard[i]) swap(keyboard[i], keyboard[0]);
        }
        FOR0(i, 63) {
            if(m[freq[1]] == keyboard[i]) swap(keyboard[i], keyboard[1]);
        }
        FOR0(i, 2000) {
            random_shuffle(keyboard + 2, keyboard + 63);
            FOR0(i, 63) {
                r[keyboard[i]] = i/21;
                c[keyboard[i]] = i % 21;
            }
            int cur = 0;
            FOR0(i, s.length()-1) {
                cur += abs(r[a[i]] - r[a[i+1]]) + abs(c[a[i]] - c[a[i+1]]);
            }
            if(cur < ans) {
                ans = cur;
                FOR0(i, 63) {
                    anskeyboard[i] = keyboard[i];
                }
            }
        }
    }
    else {
        FOR0(i, 1000) {
            int x1 = rand() % 63, x2 = rand() % 63;
            swap(keyboard[x1], keyboard[x2]);
            FOR0(i, 63) {
                r[keyboard[i]] = i/21;
                c[keyboard[i]] = i % 21;
            }
            int cur = 0;
            FOR0(i, s.length()-1) {
                cur += abs(r[a[i]] - r[a[i+1]]) + abs(c[a[i]] - c[a[i+1]]);
            }
            if(cur < ans) {
                ans = cur;
                FOR0(i, 63) {
                    anskeyboard[i] = keyboard[i];
                }
            } else swap(keyboard[x1], keyboard[x2]);
        }
    }
    // DEBUG(ans);
    FOR0(i, 3) {
        FOR0(j, 21) {
            cout << chars[anskeyboard[i*21 + j]];
        }
        cout << newl;
    }
}