class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n;i++)
        {
            int lw = lower-nums[i], up = upper - nums[i];
            ans += upper_bound(nums.begin() + (i + 1), nums.end(), up) - lower_bound(nums.begin() + (i + 1), nums.end(), lw);
        }
        return ans;
    }
};
