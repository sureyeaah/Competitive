#include <iostream>
#include <queue>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;

int main(){
    int n, x;
    cin >> n;
    while(n) {
        long long int cost = 0;
        priority_queue<int, vector<int> , greater<int> > pq;
        FOR0(i,n){
            scanf("%d", &x);
            pq.push(x);
        }
        while(pq.size() > 1) {int sum = pq.top(); pq.pop(); sum += pq.top(); pq.pop(); cost += sum; pq.push(sum);}
        cout << cost << endl;
        cin >> n;
    }
}