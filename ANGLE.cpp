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
const int N = 1e3 + 3;
int t, n, a[N], p, q;
P<int, int> COS;
int comp(P<int, int>& p1, P<int, int>& p2) {
    return (p1.first * 1LL * p2.second) <= (p2.first * 1LL * p1.second);
}
P<int, int> cosine(int A, int B, int c) {
    P<int, int> frac = {A*A + B*B - c*c, 2*A*B};
    
    return frac;
}
bool isTri(P<int, int> frac) {
    if(abs(frac.first) > abs(frac.second)) return false;
    return true;
}
int bs1(int A, int B, int st, int nd) {
    P<int, int> ans = make_pair(-1, 1);
    int ansC = -1;
    int lt = st, rt = nd; st = nd + 1;
    while(lt <= rt) {
        int mid = (lt + rt)  >> 1;
        if(isTri(cosine(A, B, a[mid]))) {
            st = mid;
            rt = mid - 1;
        } else lt = mid + 1;
    }
    while(st <= nd) {
        int mid = (st + nd) / 2;
        int c = a[mid];
        P<int, int> frac = cosine(A, B, c);
        if(comp(COS, frac)) {
            ans = frac;
            st = mid + 1;
            ansC = mid;
        } else nd = mid - 1;
    }
    return ansC;
}
void updAns(P<int, int> &ans, int A, int B, int C, int &a1, int &b, int &c) {
    
    if(C == -1) return;
    P<int, int> p = cosine(a[A], a[B], a[C]);
    if(comp(COS, p) && comp(p, ans)) {
        cerr << 1 << endl;
        ans = p;
        a1 = A;
        b = B;
        c = C;
    }
}

int main() {
    SYNC
    cin >> t;
    while(t--) {
        cin >> n >> p >> q;
        FOR0(i, n) cin >> a[i];
        sort(a, a + n);
        COS = make_pair(p, q);
        P<int, int> ans = make_pair(2, 1);
        int ansA= -1, ansB, ansC;
        if(1) {
            FOR0(i, n) {
                FOR(j, i + 1, n) {
                    auto ans1 = bs1(a[i], a[j], 0, i-1);
                    auto ans2 = bs1(a[i], a[j], i+1, j-1);
                    auto ans3 = bs1(a[i], a[j], j+1, n-1);
                    updAns(ans, i, j, ans1, ansA, ansB, ansC);
                    updAns(ans, i, j, ans2, ansA, ansB, ansC);
                    updAns(ans, i, j, ans3, ansA, ansB, ansC);
                }
            }
        }
        // cerr << ans.first << " " << ans.second << endl;
        if(ansA==-1) {cout << -1 << endl; continue;}
        cout << ansA+1 << " " << ansC+1 << " " << ansB+1 << endl;
    }
}