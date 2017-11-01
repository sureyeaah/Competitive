#include <iostream>
#include <cstring>
#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
#define MAX(a,b) ((a > b) ?(a) :(b))
#define MIN(a,b) ((a < b) ?(a) :(b))
#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))
using namespace std;
char board[8][8]; char c; int row, col, emp; string s;

void STRAIGHT() {
  FOR(i,col+1,8) { if(board[row][i] > '1') break; else board[row][i] = '1'; }
  FOR(i,row+1,8) { if(board[i][col] > '1') break; else board[i][col] = '1'; }
  for(int i = col - 1; i >= 0; i--) { if(board[row][i] > '1') break; else board[row][i] = '1'; }
  for(int i = row - 1; i >= 0; i--) { if(board[i][col] > '1') break; else board[i][col] = '1'; }
}
void DIAGONAL() {
  for(int i = 1; (row - i >= 0) && (col - i >= 0); i++) { if(board[row-i][col-i] > '1') break; else board[row-i][col-i] = '1'; }
  for(int i = 1; (row - i >= 0) && (col + i < 8); i++) { if(board[row-i][col+i] > '1') break; else board[row-i][col+i] = '1'; }
  for(int i = 1; (row + i < 8) && (col + i < 8); i++) { if(board[row+i][col+i] > '1') break; else board[row+i][col+i] = '1'; }
  for(int i = 1; (row + i >= 0) && (col - i >= 0); i++) { if(board[row+i][col-i] > '1') break; else board[row+i][col-i] = '1'; }
} 
void PAWN(bool black) {
 if(!black) {
   if(row < 7 && col < 7) {if(board[row+1][col+1] == '0') board[row+1][col+1] = '1';}
   if(col && row < 7) {if(board[row + 1][col-1] == '0') board[row+1][col-1] = '1';}
 } else {
  if(row && col) {if(board[row-1][col-1] == '0') {board[row-1][col-1] = '1';}}  
  if(col < 7 && row) {if(board[row-1][col+1] == '0') board[row-1][col+1] = '1';}
 }
}
void KING() {
 if(row < 7) {if(board[row+1][col] == '0') board[row+1][col] = '1';}
 if(row) {if(board[row-1][col] == '0') board[row-1][col] = '1';}
 if(col < 7) {if(board[row][col+1] == '0') board[row][col+1] = '1';}
 if(col) {if(board[row][col-1] == '0') board[row][col-1] = '1';}
 PAWN(true); PAWN(false);
}
int hi[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hj[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

void HORSE() {
  FOR0(i, 8) {
   if(row+hi[i] >= 0 && row + hi[i] < 8 && col +hj[i] >= 0 && col + hj[i] < 8 ) {
     if (board[row + hi[i]][col + hj[i]] == '0') board[row + hi[i]][col + hj[i]] = '1';
   }
  }
}


int main()
{
	//ios::sync_with_stdio(false);
  while(true) {
    getline(cin, s);
    if(!s.length()) break;
    memset(board, '0', 64);
    row = 0; col = 0;
    FOR0(i, s.length()) {
      c = s[i];
      if(c > '0' && c < '9') col += c-'0';
      else if(c == '/') {row++; col = 0;}
      else {
        board[row][col] = (tolower(c) == 'p') ? c : tolower(c);
        col++;  
      }
    }
    row = 0; col = 0; emp = 0;
    for(; row < 8; row++) {
      for(; col < 8; col++) {
        c = board[row][col];
        if(c == '1' || c=='0') continue;
        else if(c == 'p') PAWN(false);
        else if(c == 'P') PAWN(true);
        else if(c == 'r') STRAIGHT();
        else if(c == 'b') DIAGONAL();
        else if(c == 'k') KING();
        else if(c == 'q') {STRAIGHT(); DIAGONAL();}
        else if(c == 'n') HORSE();
      }
      col = 0;
    }
    FOR0(i, 8) {
      FOR0(j, 8) {
        if(board[i][j] == '0') {emp++;}
      }
    }
    cout << emp << endl;
  }
}