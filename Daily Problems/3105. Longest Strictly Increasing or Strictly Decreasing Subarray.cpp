class Solution {
private:
    int check(vector<int> &nums)
    {
        int maxCount = 1, cnt = 1;
        int n = nums.size();
        for(int i = 1;i <n;i++)
        {
            if(nums[i] > nums[i - 1])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            maxCount = max(maxCount, cnt);
        }
        return maxCount;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxCount = check(nums);
        reverse(nums.begin(), nums.end());
        maxCount = max(maxCount, check(nums));
        return maxCount;
    }
};
