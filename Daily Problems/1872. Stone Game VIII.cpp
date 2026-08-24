class Solution {
public:
    int n;
    int dp[100001];

    int solve(int i, vector<int> &prefixSum)
    {
        if(i == n - 1)
            return prefixSum[n-1];
        
        if(dp[i] != -1)
            return dp[i];
        
        int take = prefixSum[i] - solve(i+1,prefixSum);
        int skip = solve(i+1,prefixSum);
        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        memset(dp, -1, sizeof(dp));

        vector<int> prefixSum(n,0);
        prefixSum[0] = stones[0];
        
        for(int i = 1;i < n;i++)
            prefixSum[i] = prefixSum[i-1] + stones[i];

        return solve(1, prefixSum);
    }
};
