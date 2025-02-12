class Solution {
private:
    long long digitSum(long long number)
    {
        long long sum = 0;
        string s = to_string(number);
        for(auto i : s)
            sum += (i - '0');
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, maxi = -1;
        for(int i = 0;i < n;i++)
        {
            long long currSum = digitSum(nums[i]);
            for(int j = i + 1;j < n;j++)
            {
                long long s = digitSum(nums[j]);

                if(s == currSum)
                {
                    maxi = max(maxi, (long long) nums[i] + nums[j]);
                }
            }
        }
        return maxi;
    }
};
