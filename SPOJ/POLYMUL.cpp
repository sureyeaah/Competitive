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
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
// typedef ll to be int if you want int
// typedef ld to be double if you want double
// FFT takes a Vector of Complex numbers by reference and finds their Discrete Fourier/Inverse Fourier transform.
// Size of the Vector must be a power of 2
// To find Fourier transform the parameter inv=1, For Inverse Fourier Transform inv=-1
// The function Convolution takes two Vectors(VL), adjusts their size to be a power of 2 
// and finds their Convolution using FFT and inverse FFT and returns the convolution Vector (VL)
const long double PI=acos(-1.0);
typedef long double ld;
typedef vector<ll> VL;
int bits(int x){
    int r=0;
    while(x){
        r++;
        x>>=1;
    }
    return r;
}
int reverseBits(int x,int b){
    int r=0;
    for(int i=0;i<b;i++){
        r<<=1;
        r|=(x&1);
        x>>=1;
    }
    return r;
}
class Complex{
    public:
    ld r,i;
    Complex(){r=0.0;i=0.0;}
    Complex(ld a,ld b){r=a;i=b;}
};
Complex operator*(Complex a,Complex b){
    return Complex(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);
}
Complex operator-(Complex a,Complex b){
    return Complex(a.r-b.r,a.i-b.i);
}
Complex operator+(Complex a,Complex b){
    return Complex(a.r+b.r,a.i+b.i);
}
Complex operator/(Complex a,ld b){
    return Complex(a.r/b,a.i/b);
}
Complex EXP(ld theta){
    return Complex(cos(theta),sin(theta));
}
typedef vector<Complex> VC;
void FFT(VC& A,int inv){
    int l=A.size();
    int b=bits(l)-1;
    VC a(A);
    for(int i=0;i<l;i++){
        A[reverseBits(i,b)]=a[i];
    }
    for(int i=1;i<=b;i++){
        int m=(1<<i);
        int n=m>>1;
        Complex wn=EXP((ld)inv*(ld)2.0*PI/(ld)m);
        for(int j=0;j<l;j+=m){
            Complex w(1.0,0.0);
            for(int k=j;k<j+n;k++){
                Complex t1=A[k]+w*A[k+n];
                Complex t2=A[k]-w*A[k+n];
                A[k]=t1;
                A[k+n]=t2;
                w=w*wn;
            }
        }
    }
    if(inv==-1){
        for(auto &i:A){
            i=i/(ld)l;
        }
    }
}
VL Convolution(VL a,VL b){
    int l1=a.size()+b.size();
    int bit=bits(l1);
    int l=1<<bit;
    a.resize(l,0LL);
    b.resize(l,0LL);
    VC A,B,C;
    for(auto i:a){
        A.push_back(Complex((ld)i,0));
    }
    for(auto i:b){
        B.push_back(Complex((ld)i,0));
    }
    FFT(A,1);
    FFT(B,1);
    for(int i=0;i<l;i++){
        C.push_back(A[i]*B[i]);
    }
    FFT(C,-1);
    VL c;
    for(auto i:C){
        c.push_back(round(i.r));
    }
    return c;
}

int main() {
    SYNC
    int t, n;
    VL a, b;
    cin >> t;
    while(t--) {
        cin >> n;
        a.resize(n+1); b.resize(n+1);
        FOR0(i, n+1) cin >> a[n-i];
        FOR0(i, n+1) cin >> b[n-i];
        VL ans = Convolution(a, b);
        FORD(i,1,2*n+1) cout << ans[i] << " ";
        cout << ans[0] << '\n';
    }
}