// Gear4        
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define SYNC std::ios::sync_with_stdio(false);  cin.tie(NULL);
#define ff first
#define ss second
template<typename T> using V = vector<T>;
template<typename T, typename U> using P = pair<T,U>;
using ld = long double;
using ll = long long;
#define endl '\n'
const int inf = 1e9, mod = 1e9 + 7;
const ll INF = 9e18;
const ld EPS = 1e-9, PI = acosl(-1.0);

struct TileFlippingGame
{
    int n; 
    int m; 
    vector<string> X;
    int vis[25][25] = {};
    set<int> G[2][405];
    int dx[4] = {1, 0, -1, 0}, dy[4]={0, 1, 0, -1};
    int cnt[2] = {};
    void dfs(int i, int j) {
        vis[i][j] = cnt[X[i][j]=='b'];
        FOR0(d, 4) {
            int ni = dx[d] + i, nj = dy[d] + j;
            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(X[i][j] == X[ni][nj] && !vis[ni][nj]) dfs(ni, nj);
            if(vis[ni][nj] && X[i][j] != X[ni][nj]) G[X[i][j]=='b'][vis[i][j]].insert(vis[ni][nj]),
                G[X[ni][nj]=='b'][vis[ni][nj]].insert(vis[i][j]);
        }
    }
    int solve(int c) {
        int done[2][405] = {};
        int ret = 0;

        FOR(i, 1, cnt[c]+1) {
            int x = 0;
            done[c][i] = 1;
            for(int j : G[c][i]) {
                if(!done[c^1][j]) x++;
            }
            if(x == 4) {
                ret += 2;
                for(int j : G[c][i]) {
                    done[c^1][j] = 1;
                }
            }
        }
        FOR(i, 1, cnt[c]+1) {
            int x = 0;
            if(done[c][i]) continue;
            done[c][i] = 1;
            for(int j : G[c][i]) {
                if(!done[c^1][j]) x++;
            }
            if(x == 3) {
                ret += 2;
                for(int j : G[c][i]) {
                    done[c^1][j] = 1;
                }
            }
        }
        FOR(i, 1, cnt[c^1] + 1) if(!done[c^1][i]) ret++;
        return ret;
    }
    int HowManyMoves(int n, int m, vector<string> X)
    {
        this->n = n;
        this->m = m; 
        this->X = X;
        
        FOR0(i, n) {
            FOR0(j, m) {
                if(X[i][j] != 'e' && !vis[i][j]) ++cnt[X[i][j]=='b'], dfs(i,j);
            }
        }
        return min(solve(0), solve(1));
    }
};

// CUT begin
ifstream data("TileFlippingGame.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int m, vector<string> X, int __expected) {
    time_t startClock = clock();
    TileFlippingGame *instance = new TileFlippingGame();
    int __result = instance->HowManyMoves(n, m, X);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int n;
        from_stream(n);
        int m;
        from_stream(m);
        vector<string> X;
        from_stream(X);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, m, X, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1522378078;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TileFlippingGame (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
