class Solution {
public:
    int N = 25, inf=1e8;
    int n, m;
    void loc(int i, int &r, int &c) {
        r = (i-1) / n, c = (i-1) % n;
            c = r & 1 ? n - 1 - c: c; r = n - 1 - r;
        
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size(), m = n * n;
        vector<vector<int>> g(m + 1);
        vector<int> dist(m + 1, inf);
        for(int i = 1; i <= n*n; i++) {
            for(int j = i+1; j <= min(n*n, i+6); j++) {
                int r, c;
                loc(j, r, c);    
                if(board[r][c] != -1)
                    g[i].push_back(board[r][c]);
                else g[i].push_back(j);
            }
            
            
        }
        queue<int> q({1}); dist[1] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : g[u]) {
                if(dist[v] != inf) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        // return dist[35];
        return dist[m] == inf ? -1: dist[m];
    }
};
