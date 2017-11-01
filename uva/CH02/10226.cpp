#include <iostream>
#include <map>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int main()
{
    int n;
    char c;
    map<string, int> trees;
    string s = "";
    scanf("%d", &n); cin.ignore(); cin.ignore();
    while (n--)
    {
        int numT = 0;
        while (true)
        {
            while (c = getchar(), (c != '\n' && c!=EOF)) {s += c;}
            if (!s.length())
                break;
            trees[s]++; numT++;
            s = "";
        }
        for (map<string, int>::iterator i = trees.begin(); i != trees.end(); i++)
        {
            cout << i->first; printf(" %.4f\n", 100* ((float)i->second) / ((float)numT));
        }
        if(n>0) {cout << endl; trees.clear();}
    }
}