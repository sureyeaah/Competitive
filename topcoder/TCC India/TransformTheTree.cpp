#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define SZ(a) ((int)((a).size()))
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF ((int)1e9)
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 55;
vvi g(N);
int dp[N][3] = {};
struct TransformTheTree
{
    vector<int> parents; 
    
    void dfs(int u, int prev) {
        int cnt  = 0;
        for(int v : g[u]) {
            if(v == prev) continue;
            dfs(v, u);
            cnt++;
        }
        dp[u][0] = dp[u][1] = 0;
        if (cnt == 1) {
            for(int v : g[u]) {
                if(v != prev) {
                    dp[u][0] = dp[u][1] = dp[v][2];
                }
            }
        } else if(cnt) {
            int val = INF;
            priority_queue<int> pq;
            for(int v : g[u]) {
                if(v != prev) {
                    int x = min(dp[v][0], dp[v][1]);
                    dp[u][1] += 1 + x;
                    val = min(val, dp[v][2] - (1 + x));
                    pq.push(dp[v][2] - (1 + x));
                    if(pq.size() > 2) pq.pop();
                }
            }
            dp[u][0] = dp[u][1];
            dp[u][1] += val;
            while(!pq.empty()) {
                dp[u][0] += pq.top(); pq.pop();
            }
        }
        dp[u][2] = min(dp[u][0] + 1, dp[u][1]);
    }
    int countCuts(vector<int> parents)
    {
        this->parents = parents; 
        FOR0(i, SZ(parents)) {
            g[parents[i]].pb(i+1);
            g[i+1].pb(parents[i]);
        }
        int ans = 10000000;
        FOR0(i, parents.size() + 1) {
            dfs(i,-1);
            ans = min(ans, min(dp[i][0], dp[i][1]));
        }
        return ans;
    }
};

// CUT begin
ifstream data("TransformTheTree.sample");

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

bool do_test(vector<int> parents, int __expected) {
    time_t startClock = clock();
    TransformTheTree *instance = new TransformTheTree();
    int __result = instance->countCuts(parents);
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
        vector<int> parents;
        from_stream(parents);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parents, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1501344429;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 600 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TransformTheTree (600 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
