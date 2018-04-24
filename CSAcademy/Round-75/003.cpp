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
int n, x, y; const int N = 1e5 + 5;
struct car {
    ll d, v;
    int id;
    car () {};
    car (ll _d, ll _v, int _id) {d= _d, v= _v, id= _id;}
    bool operator< (car other) {
        ll val = d*other.v - other.d*v;
        return val ? val < 0: id < other.id;
    }
};
car cars[N];
int ans[N];
int main() {
    SYNC
    cin >> n >> x >> y;
    FOR0(i, n) {
        cin >> cars[i].d >> cars[i].v;
        cars[i].id=i;
    }
    sort(cars, cars + n);
    FOR0(i, n) {
        int pos = i;
        int l = 0, r = i - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(car(cars[i].d, cars[i].v + x, cars[i].id) < cars[mid])
                pos = mid, r = mid-1;
            else l = mid + 1;
        }
        ans[cars[i].id] = pos+1;
    }
    FOR0(i, n) cars[i].v -= y;
    sort(cars, cars + n);
    FOR0(i, n) {
        int pos = i;
        int l = 0, r = i - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(car(cars[i].d, cars[i].v + y, cars[i].id) < cars[mid])
                pos = mid, r = mid-1;
            else l = mid + 1;
        }
        ans[cars[i].id] = min(ans[cars[i].id], pos+1);
    }
    FOR0(i, n) cout << ans[i] << " ";
}