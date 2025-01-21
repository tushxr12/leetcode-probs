class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long topSum = 0, bottomSum = 0;
        long long ans = LLONG_MAX;
        long long n = grid[0].size();
        for(int i = 0;i < n;i++)
        {
            topSum += grid[0][i];
        }

        for(int i = 0;i < n;i++)
        {
            topSum -= grid[0][i];
            ans = min(ans, max(topSum, bottomSum));
            bottomSum += grid[1][i];
        }
        return ans;
    }
};
