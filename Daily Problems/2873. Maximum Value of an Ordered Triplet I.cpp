class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                for(int k = j + 1;k <n;k++)
                {
                    long long  res = (nums[i] - nums[j]);
                    res *= nums[k];
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};
