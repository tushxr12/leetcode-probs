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

// Better
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for(int i = 1;i < n;i++)
        {
            if(nums[i] < firstMin)
            {
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i] < secondMin)
            {
                secondMin = nums[i];
            }
        }

        return (ans + firstMin + secondMin);
    }
};
