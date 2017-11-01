#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define FOR0(i, n) for (int i = 0; i < n; i++)
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define ABS(a) ((a < 0) ? ((-1) * (a)) : (a))
int geti()
{
    char c;
    int ret = 0;
    bool start = false;
    while (true)
    {
        c = getchar();
        if ((c - '0' < 0 || c - '0' > 9) && !start)
        {
            continue;
        }
        if ((c - '0' < 0 || c - '0' > 9) && start)
        {
            break;
        }
        if (start)
            ret *= 10;
        start = true;
        ret += c - '0';
    }
    return ret;
}
using namespace std;

class pairComp
{
  public:
    bool operator()(pair<int, int> n1, pair<int, int> n2)
    {
        if (n1.first > n2.first)
            return true;
        if (n1.first == n2.first)
            return n1.second > n2.second;
        return false;
    }
};

int main()
{
    char c;
    priority_queue<pair<int, int>, vector<pair<int, int>>, pairComp> pq;
    pair<int, int> inst[1000];
    int mini = 3001, maxi = 0, a, b, index = 0;
    while (true)
    {
        c = getchar();
        if (c == '#')
            break;
        cin.ignore(10, ' ');
        a = geti();
        b = geti();
        mini = MIN(mini, b);
        maxi = MAX(maxi, b);
        inst[index] = make_pair(b, a);
        index++;
    }
    int k = geti();
    //sort(inst, inst+index);
    for (int l = 1; pq.size() <= k; l++)
    {
        FOR0(i, index)
        {
            int curr = inst[i].first, currQ = inst[i].second;
            for (int j = 1; curr*j + ((int)maxi*(l-1)/curr)*curr <= maxi * l; j++)
            {
                pq.push(make_pair(curr*j + ((int)maxi*(l-1)/curr)*curr, currQ));
            }
        }
    }
    while (k--)
    {
        cout << pq.top().second << endl;
        pq.pop();
    }
}