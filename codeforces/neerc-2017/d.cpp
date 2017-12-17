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
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
vector<pair<ii,int> > fans;
int main() {
    SYNC
    int un=0;
    vector<ii> a(3);
    for(int i=0;i<3;i++){
        cin>>a[i].first;
        a[i].second=2-i;
    }
    sort(a.begin(), a.end());
    if(a[0].fi*a[1].fi <a[2].fi){
        cout<<-1;
        return 0;
    }
    while(a[2].fi <(a[0].fi+a[1].fi-1)){
        a[0].fi--;
        a[1].fi--;
        a[2].fi--;
        un++;
    }
    int tot=a[2].fi;
    for(int i=0;i<a[0].fi;i++){
        vector<ii> ans;
        ans.pb({a[2].se,100});
        ans.pb({a[0].se,0});
        ans.pb({a[1].se,i});
        sort(ans.begin(), ans.end());
        fans.pb({{ans[0].second,ans[1].second},ans[2].second});
        tot--;
    }
    for(int i=1;i<a[1].fi;i++){
        vector<ii> ans;
        ans.pb({a[2].se,100});
        ans.pb({a[0].se,i});
        ans.pb({a[1].se,0});
        sort(ans.begin(), ans.end());
        fans.pb({{ans[0].second,ans[1].second},ans[2].second});
        tot--;
    }
    for(int i=1;i<a[0].fi;i++) if(tot){
        for(int j=1;j<a[1].fi;j++) if(tot){
            tot--;
            vector<ii> ans;
            ans.pb({a[2].se,100});
            ans.pb({a[0].se,j});
            ans.pb({a[1].se,i});
            sort(ans.begin(), ans.end());
            fans.pb({{ans[0].second,ans[1].second},ans[2].second});
        }
    }
    while(un--){
        fans.pb({{un-100,un-100},un-100});
    }
    cout<<(int)fans.size()<<"\n";
    for(auto i:fans){
        cout<<i.fi.fi<<" "<<i.fi.se<<" "<<i.se<<"\n";
    }
}