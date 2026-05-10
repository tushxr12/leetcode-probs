class Solution {
public:
    int n;
    int solve(int index, vector<int> &nums, int target, vector<int> &dp)
    {
        if(index == n-1)
            return dp[index] = 0;
        
        if(dp[index] != INT_MIN)
            return dp[index];

        int res = INT_MIN;
        for(int j = index + 1;j < n;j++){
            if(abs(nums[index] - nums[j]) <= target){
                int temp = 1 + solve(j, nums, target, dp);

                res = max(res, temp);
            }
        }

        return dp[index] = res;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        vector<int> dp(n + 1, INT_MIN);
        int res = solve(0, nums, target, dp);
        return res < 0 ? -1 : res;
    }
};
