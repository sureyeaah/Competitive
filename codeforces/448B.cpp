#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  char s[101], t[101];
  int ls, lt;
  ls = lt = 0;
  while(s[ls] = getchar(), s[ls]!='\n') {
    ls++;
  }
  while(t[lt] = getchar(), t[lt]!='\n') {
    lt++;
  }
  if(ls == lt) {
    sort(s,s+ls);
    sort(t,t+lt);
    for(int i = 0; i < ls; i++){
      if(s[i] != t[i]) {cout << "need tree" << endl; return 0;}
    }
    cout << "array" << endl;
  } else if(lt < ls){
    char* j = s;
    int i = 0;
    for(; i < lt && j < s+ls; i++) {
      char* loc = find(j,s+ls,t[i]);
      if(loc != s+ls) j= loc+1;
      else break;
    }
    if(i == lt && j <= s+ls) {cout << "automaton" << endl; return 0;}
    sort(s,s+ls);
    sort(t,t+lt);
    j = s;
    i = 0;
    for(; i < lt && j < s+ls; i++) {
      char* loc = find(j,s+ls,t[i]);
      if(loc != s+ls) j= loc+1;
      else {cout << "need tree" << endl; return 0;}
    }
    if(i == lt && j <= s+ls) {cout << "both" << endl; return 0;} else {
      cout << "need tree" << endl; return 0;
    }
  } else {
    cout << "need tree" << endl;
  }
}
