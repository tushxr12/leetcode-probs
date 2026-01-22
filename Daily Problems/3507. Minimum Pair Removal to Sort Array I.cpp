class Solution {
public: 
    int minPairSum(vector<int> &nums)
    {
        int minSum = INT_MAX;
        int index = -1;
        int n = nums.size();

        for(int i = 0;i < n - 1;i++)
        {
            if(nums[i] + nums[i+1] < minSum)
            {
                minSum = nums[i] + nums[i+1];
                index = i;
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans = 0;
        while(!is_sorted(begin(nums), end(nums)))
        {

            int index = minPairSum(nums);
            nums[index] = nums[index] + nums[index+1];
            nums.erase(begin(nums) + index + 1);
            ans++;
        }
        return ans;
    }
};
