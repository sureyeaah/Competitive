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
int a[1001];
vector<int> ans;
multiset<int> s;
int main() {
    SYNC
    int n;
    cin>>n;
    int u=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>0)
            s.insert(a[i]);
        else if(a[i]==0){
            u++;
        }
        else{
            if(s.find(-a[i])!=s.end()){
                s.erase(s.find(-a[i]));
            }
            else if(u>0){
                u--;
                ans.pb(-a[i]);
            }
            else{
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    for(auto i:ans)
        cout<<i<<" ";
    while(u--){
        cout<<1<<" ";
    }
}