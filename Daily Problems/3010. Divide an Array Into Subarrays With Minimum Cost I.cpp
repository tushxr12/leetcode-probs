class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];

        int n = nums.size();

        sort(begin(nums) + 1, end(nums));
        ans += nums[1] + nums[2];
        return ans;
    }
};
