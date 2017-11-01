#include <iostream>
#include <vector>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
/*
int main(){
    unsigned int n ;
    vector <unsigned int> v;
    while(cin >> n) {
        v.push_back(n);
        sort(v.begin(), v.end());
        cout << (v[v.size()/2] + v[(v.size()-1)/2])/2<< endl;
    }
}*/
int main() {
    int l = 0, k;
    unsigned int n, v[10000];
    while(cin >> n) {
        k = lower_bound(v,v+l,n) - v;
        l++;
        for(int i = l-1; i >= k+1; i--) {
            v[i] = v[i-1];
        }
        v[k] = n;
        cout << (v[l/2] + v[(l-1)/2])/2 << endl;
    }
}