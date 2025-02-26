class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        for(int i = 0;i <n;i++)
        {
            int currSum = 0;
            for(int j = i;j < n;j++)
            {
                currSum += nums[j];
                maxSum = max(maxSum, abs(currSum));
            }
        }
        return maxSum;
    }
};
