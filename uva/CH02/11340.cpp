#include <iostream>
#include <map>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
map<char,int> num;
map<char, int> article;
int main(){
    int n, k, m,x; char c;
    cin >> n;
    while(n--) {
        num.clear(); article.clear();
        int value = 0;
        cin >> k;
        FOR0(i, k) {
            cin >> c >> x;
            num[c] = x;
        }
        cin >> m;
        c=getchar();
        while(m--) {
            while(c=getchar(), c!= '\n') {
                if(article.find(c) != article.end()) article[c]++;
                else article[c] = 1;
            }
        }
        for(map<char,int>::iterator i = article.begin(); i!=article.end(); ++i) {
            c = i->first;
            if(num.find(c) != num.end()) {
                value += i->second * num[c];
            }
        }
        printf("%d.%02d$\n", value/100, value%100);
    }
}