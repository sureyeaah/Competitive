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
#define MOD (1000000000 + 0)
#define newl '\n'
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
#define dzx cerr<<"here";
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll dp[1<<8];
ll c[1<<8][1<<8];
int n;
ll calc(int msk){
    int tdp[9];
    tdp[0]=1;
    for(int j=0;j<n;j++){
        if(msk&(1<<j)){
            tdp[j+1]=tdp[j];
        }
        else{
            tdp[j+1]=tdp[j];
            if(j && !(msk&(1<<(j-1))))
                tdp[j+1]=(tdp[j-1]+tdp[j])%MOD;
        }
    }
    return tdp[n];
}
void mult(ll a[][1<<8],ll b[][1<<8],ll c[][1<<8],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll t=0;
            for(int k=0;k<n;k++){
                t=(t+a[i][k]*b[k][j])%MOD;;
            }
            c[i][j]=t;
        }
    }
}
ll r[2][1<<8][1<<8];
ll mat[2][1<<8][1<<8];
int exp(ll e,int n){
    int i=0;
    int j=0;
    memset(r,0,sizeof r);
    for(int i=0;i<n;i++){
        r[0][i][i]=1;
        r[1][i][i]=1;
    }
    while(e){
        if(e&1){
            mult(r[j],mat[i],r[j^1],n);
            j^=1;
        }
        e>>=1;
        mult(mat[i],mat[i],mat[i^1],n);
        i^=1;
    }
    return j;
}
int main() {
    SYNC
    ll m;
    cin>>n>>m;
    for(int i=0;i<(1<<n);i++){
        dp[i]=calc(i);
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<n);j++){
            if(!(i&j))
                c[i][j]=dp[i|j];
            else
                c[i][j]=0;
            mat[0][i][j]=c[i][j];
        }
    }
    int j=exp(m-1,(1<<n));
    ll ans=0;
    for(int i=0;i<(1<<n);i++){
        ans=(ans+r[j][i][0]*dp[i])%MOD;
    }
    cout<<ans;
}