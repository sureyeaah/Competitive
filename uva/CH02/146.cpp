#include <iostream>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
char c, input[50]; int l;
void reverse(int start, int end)
{
    FOR(i, start, (end + 1 + i) / 2)
    {
        c = input[start];
        input[start] = input[end - start];
        input[end - start] = c;
    }
}
int main()
{
    while (true)
    {
        l = 0;
        while (c = getchar(), c != '\n')
        {
            input[l] = c;
            l++;
        }
        if (input[0] == '#')
            break;
        int i = l - 1;
        for (; i > 0; i--)
        {
            if (input[i] > input[i - 1])
                break;
        }
        if (!i)
            printf("No Successor\n");
        else
        {
            i--;
            FOR0(j,i) cout << input[j];
            int k = l-1;
            for(; k > i; k--) {
                if(input[k] > input [i]) {cout << input[k]; input[k] = input[i]; break;}
            }
            for(int j = l-1; j > i; j--)
                cout << input[j];
            cout << endl;
        }
    }
}