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

//Better
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currPositiveSum = 0, currNegativeSum = 0;

        for(auto i : nums)
        {
            //Positive
            currPositiveSum += i;
            maxSum = max(maxSum, currPositiveSum);
            if(currPositiveSum < 0)
                currPositiveSum = 0;
            
            //Negative
            currNegativeSum += i;
            minSum = min(minSum, currNegativeSum);
            if(currNegativeSum > 0)
                currNegativeSum = 0;
        }
        return max(maxSum, abs(minSum));
    }
};
