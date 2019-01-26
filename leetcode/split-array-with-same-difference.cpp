class Solution {
public:
    bitset<30*10005> dp[35];
    bool splitArraySameAverage(vector<int>& A) {
        int n = A.size();
        int s = accumulate(A.begin(), A.end(), 0);
        dp[0][0] = 1;
        for(int i = 0; i < n; i ++) {
            for(int x = s-1; x >= A[i]; x--) {
                for(int y = i; y >= 0; y--) {
                    dp[y+1][x] = dp[y+1][x] | dp[y][x-A[i]];
                    if(dp[y+1][x] && x * n == s * (y+1)) return true;
                }
            }
        }
        return false;
    }
};