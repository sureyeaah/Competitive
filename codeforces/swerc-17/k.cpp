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
typedef long double ld;
ll n,r;
struct Point{
    ll x,y;
    Point(){x=0;y=0;}
    Point(ll x,ll y):x(x),y(y){

    }
    ll operator*(Point b){
        return x*b.y-y*b.x;
    }
    Point operator-(Point b){
        return Point(x-b.x,y-b.y);
    }
    Point operator+(Point b){
        return Point(x+b.x,y+b.y);
    }
};
ll mag(Point a){
    return a.x*a.x+a.y*a.y;
}
ld dist(Point a,Point b,Point c){
    ld l=sqrtl((ld)mag(a-b));
    ld ar=(ld)abs(((a-c)*(b-c)));
    return ar/l;
}
vector<Point> pts;
vector<Point> uh;
vector<Point> lh;
int main() {
    SYNC
    cin>>n>>r;
    pts.resize(n);
    for(int i=0;i<n;i++){
        cin>>pts[i].x>>pts[i].y;
    }
    sort(pts.begin(),pts.end(),[](Point &a,Point &b){
        if(a.x==b.x)
            return a.y<b.y;
        return a.x<b.x;
    });
    uh.pb(pts[0]);
    uh.pb(pts[1]);
    for(int i=2;i<n;i++){
        while((int)uh.size()>1){
            Point p1=uh[(int)uh.size()-2];
            Point p2=uh.back();
            if(((p1-pts[i])*(p2-pts[i]))>=0){
                uh.pop_back();
            }
            else
                break;
        }
        uh.pb(pts[i]);
    }
    lh.pb(pts[0]);
    lh.pb(pts[1]);
    for(int i=2;i<n;i++){
        while((int)lh.size()>1){
            Point p1=lh[(int)lh.size()-2];
            Point p2=lh.back();
            if(((p1-pts[i])*(p2-pts[i]))<=0){
                lh.pop_back();
            }
            else
                break;
        }
        lh.pb(pts[i]);
    }
    lh.pop_back();
    reverse(lh.begin(),lh.end());
    for(auto i:lh)
        uh.pb(i);
    uh.pop_back();
    ld ans;
    ld mx=0;
    int idx=0;
    for(int i=2;i<(int)uh.size();i++){
        ld d=dist(uh[0],uh[1],uh[i]);
        if(mx<d){
            mx=d;
            idx=i;
        }
    }
    ans=mx;
    int s=(int)uh.size();
    int p=idx;
    for(int i=1;i<s;i++){
        while(dist(uh[i],uh[(i+1)%s],uh[p])<dist(uh[i],uh[(i+1)%s],uh[(p+1)%s])){
            p=(p+1)%s;
        }
        ans=min(ans,dist(uh[i],uh[(i+1)%s],uh[p]));
    }
    cout<<fixed<<setprecision(16)<<ans;
    return 0;
}