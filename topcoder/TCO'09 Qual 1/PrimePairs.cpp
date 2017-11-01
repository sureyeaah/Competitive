#include <bits/stdc++.h>
using namespace std;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define FOR0(i,n) for(int i=0, _##i=(n); i<_##i; ++i)
#define FOR(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define FORD(i,l,r) for(int i=(r), _##i=(l); --i>=_##i; )
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i; ++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(), _##i=(a).rend(); i!=_##i; ++i)
#define printCase() "Case #" << caseNum << ": "
#define pb push_back
#define mp make_pair
#define INF (int)1e9
#define EPS 1e-9
#define SYNC std::ios::sync_with_stdio(false)
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
class PrimePairs {
    public:
    bitset<2001> bs;
    void sieve() {
        bs.set(); bs[0] = bs[1] = 0;
        FOR(i,2,2001) {
            if(bs[i]) {
                for(int j = i*i; j <= 2000; j += i) bs[j] = 0;
            }
        }
    }
    vector<int> matches(vector<int> numbers) {
        sieve();
        int f;
        int n = numbers.size(), s = n, t = n+1, zero = numbers[0]&1;
        vi arr[2];
        FOR0(i, numbers.size()) arr[numbers[i]&1].pb(i);
        vi output;
        if(arr[0].size() != arr[1].size()) return output;
        int res[55][55]; memset(res,0,sizeof res);
        int p[55];
        FOR0(i, n/2) {
            memset(res, 0, sizeof res);
            FOR0(j, n/2) res[s][arr[zero][j]] = 1;
            FOR0(j, n/2) res[arr[1-zero][j]][t] = 1;
            if(bs[numbers[arr[zero][0]] + numbers[arr[1-zero][i]]]) res[arr[zero][0]][arr[1-zero][i]] = 1;
            else continue;
            FOR(j, 1, n/2) FOR0(k, n/2) if(bs[numbers[arr[zero][j]] + numbers[arr[1-zero][k]]]) res[arr[zero][j]][arr[1-zero][k]] = 1;
            int mf = 0;
            while(1) {
                queue<int> q; q.push(s); FOR0(j, n+2) p[j] = -1; p[s] = s;
                while(!q.empty()) {
                    int u = q.front(); q.pop();
                    if(u == t) break;
                    FOR0(r, n+2) if(p[r]==-1 && res[u][r]) {p[r] = u; q.push(r);}
                }
                f = INF;
                int u = t;
                while(u != s) {
                    if(p[u] == -1) {f = 0; break;}
                    else f = min(f, res[p[u]][u]);
                    u = p[u];
                }
                if(!f || f == INF) break;
                u = t;
                while(u != s) {
                    res[u][p[u]] += f;
                    res[p[u]][u] -= f;
                    u = p[u];
                }
                mf += f;
            }
            if(mf == n/2) output.pb(numbers[arr[1-zero][i]]);
        }
        sort(output.begin(), output.end());
        return output;
    }
};

// CUT begin
ifstream data("PrimePairs.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(vector<int> numbers, vector<int> __expected) {
    time_t startClock = clock();
    PrimePairs *instance = new PrimePairs();
    vector<int> __result = instance->matches(numbers);
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
        vector<int> numbers;
        from_stream(numbers);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(numbers, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1495176132;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "PrimePairs (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
