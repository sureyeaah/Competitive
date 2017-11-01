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
  while(true) {
    string s;
    getline(cin,s);
    if(s[0] == 'G') break;
    int l = s.length(), strikes = 0, score = 0, prev1 = 0, prev2 = 0, index = l-1;
    for(int i = 0; i < l; i++){
      if(s[i] == 'X') strikes++;
    }
    if((l+1)/2 + strikes > 20) {
      if(s[l-3] == '/') {prev1 = s[l-1] == 'X' ? 10 : s[l-1] - '0'; index = l-3;}
      else {
        prev1 = s[l-3] == 'X' ? 10 : (s[l-3] - '0');
        if(s[l-1] == 'X') prev2 = 10;
        else if(s[l-1] == '/') prev2 = 10-prev1;
        else prev2 = s[l-1] - '0';
        index = l-5;
      }
    }
    for(;index >= 0; index -=2) {
      if(s[index] == 'X') {
        score += prev1 + prev2 + 10;
        prev2 = prev1; prev1 = 10;
      }
      else if(s[index] == '/') {
        score += prev1 + 10;
        index -= 2;
        prev1 = s[index] - '0'; prev2 = 10-prev1;
      } else {
        prev2 = s[index] - '0';
        index -= 2;
        prev1 = s[index] - '0';
        score += prev1 + prev2;
      }
    }
    cout << score << endl;
  }
}
