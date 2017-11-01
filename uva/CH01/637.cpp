#include <iostream>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j,n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
  int n;
  while(true) {
    cin >> n;
    if(!n) break;
    cout << "Printing order for " << n << " pages:" << endl;
    int up = n + (n%4==0 ? 0: 4-(n%4));
    int sheets = up/4, s=1, pgno = 1;
    for(; pgno <= ((n==3||n==4)?2:MIN(3,n)); pgno+=2) {
      cout << "Sheet " << s << ", front: ";
      if(up-pgno+1 > n) cout << "Blank"; else cout << up-pgno+1;
      cout << ", " << pgno << endl;
      if(pgno+1 <= n) {
        cout << "Sheet " << s << ", back : " << pgno+1 << ", ";
        if(up-pgno > n) cout << "Blank"; else cout << up-pgno;
        cout << endl;
      }
      s++;
    }
    for(; s <= sheets; s++) {
      cout << "Sheet " << s << ", front: " << up-pgno+1 << ", " << pgno << endl;
      pgno++;
      cout << "Sheet " << s << ", back : " << pgno << ", " << up-pgno+1 << endl;
      pgno++;
    }
  }
}
