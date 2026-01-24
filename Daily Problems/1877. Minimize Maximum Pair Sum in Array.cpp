class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int n = nums.size();

        int ans = 0;
        int i = 0, j =n - 1;
        while(i < j)
        {
            ans = max(ans, nums[i] + nums[j]);
            i++;j--;
        }
        return ans;
    }
};
