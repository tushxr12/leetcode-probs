class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans = 1;
        int n = nums.size();
        ans *= (nums[n-1] - 1);
        ans *= (nums[n-2] - 1);
        return ans;
    }
};
