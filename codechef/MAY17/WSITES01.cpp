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
struct TRIE {
	TRIE* next[26];
	bool leaf = false;
};
TRIE* root;

string s;

void insert() {
	TRIE* curr = root, *prev = NULL;
	int i = 0;
	while(curr && i < s.length()) {
		prev = curr;
		curr = curr->next[s[i]-'a'];
		i++;
	}
	i--;
	while(i < s.length()) {
		prev = prev->next[s[i]-'a'] = (TRIE*) malloc(sizeof(TRIE));
		FOR0(i, 26) prev->next[i] = NULL;
		i++;
	}
	prev->leaf = true;
}

int main() {
	SYNC;
	bool poss = true;
	root = (TRIE*) malloc(sizeof(TRIE));
	FOR0(i, 26) root->next[i] = NULL;
	int n; char type;
	vector<string> bl, op;
	cin >> n;
	while(n--) {
		cin >> type >> s;
		if(type == '+') {
			insert();
		} else {
			bl.pb(s);
		}
	}
	sort(bl.begin(), bl.end());
	string curr = "";
	repi(str, bl) {
		if(curr.length() && curr.length() <= (*str).length()) {
			bool works = true;
			FOR0(j, curr.length()) if(curr[j] != (*str)[j]) {
				works = false; break;
			}
			if(works) continue;
		}
		curr = "";
		TRIE* it = root;
		FOR0(j, (*str).length()) {
			if(it->next[(*str)[j] - 'a']) it = it->next[(*str)[j] - 'a'];
			else {
				curr = (*str).substr(0, j+1);
				break;
			}
		}
		if(curr.length()) op.pb(curr);
		else {
			poss = false; break;
		}
	}
	if(poss) {
		cout << op.size() << endl;
		repi(i, op) cout << *i << endl;
	} else cout << -1 << endl;
}