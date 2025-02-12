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

//Better
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
        map<int,int> mpp;
        for(auto i : nums)
        {
            long long digitSumm = digitSum(i);
            if(mpp.find(digitSumm) != mpp.end())
            {
                int prevNum = mpp[digitSumm];
                maxi = max(maxi, (long long)prevNum + i);
                mpp[digitSumm] = max(i, prevNum);
            }
            else
            {
                mpp[digitSumm] = i;
            }
        }
        return maxi;
    }
};
