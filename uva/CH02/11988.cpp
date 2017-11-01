#include <iostream>
#include <list>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
using namespace std;
int main()
{

    list<string> out;
    string s = "";
    char c;
    bool tostart = true;
    while (true)
    {
        while (c = getchar(), c != EOF)
        {
            if (c == '[' || c == ']' || c=='\n')
            {
                if (s.length())
                {
                    if (tostart)
                        out.push_front(s);
                    else
                        out.push_back(s);
                    s = "";
                }
                if(c=='\n') break;
                tostart = (c == '[') ? true : false;
            }
            else
                s += c;
        }
        for (list<string>::const_iterator iterator = out.begin(), end = out.end(); iterator != end; ++iterator)
        {
            std::cout << *iterator;
        }
        if (out.size())
            cout << endl;
        out.clear();
        if (c == EOF)
            break;
    }
}