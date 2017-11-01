#include <iostream>
#include <vector>
#include <algorithm>
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
#define PI 3.14159265

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
    int t, p, x, y;
    scanf("%d", &t);
    FOR(case_number, 1, t+1) {
        scanf("%d%d%d", &p, &x, &y);
        x -= 50; y -= 50;
        double distance = sqrt(x*x + y*y);
        if(distance > 50) {
            printf("Case #%d: white\n", case_number);
        } else {
            double opp = sqrt((double)(x*x + (y-50)*(y-50)));
            double anglePercent = acos((2500.0 + distance*distance -opp*opp)/(2.0*50.0*distance))/(2.0*PI)*100.0;
            if(x < 0) anglePercent = 100.0 - anglePercent;
            if(anglePercent < p) printf("Case #%d: black\n",case_number);
            else printf("Case #%d: white\n", case_number);
        }
    }
}