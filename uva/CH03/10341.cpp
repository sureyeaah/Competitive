#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
#define INF 1000000000
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int p, q, r, s, t, u;

double func(double f) {
    return p*exp(-f) + q*sin(f) + r*cos(f) + s*tan(f) + t*f*f + u;
}

double Round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

double error = 1e-8;
int main() {
    while(cin >> p) {
        scanf("%d%d%d%d%d", &q,&r,&s,&t,&u);
        // bool solutionExists, sol;
        if(p+r+u < 0 || func(1.0) > 0.0) {
            printf("No solution\n");
        } else {
            double a = 0.0, b = 1.0;
            while(b-a > error) {
                double mid = func((a+b)/2.0);
                if(mid > 0) a = (a+b)/2.0;
                else b = (a+b)/2.0;
            }
            printf("%.04f\n", (Round( ((a+b)/2) * 10000.0 ) / 10000.0));
        }
    }
}