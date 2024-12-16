class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // sort(nums.begin(), nums.end());
        //[1,2,3,5,6]
        int n = nums.size();
        while(k--)
        {
            int mini = INT_MAX, ind = -1;
            for(int i = 0;i < n;i++)
            {
                if(nums[i] < mini)
                {
                    mini = min(mini,nums[i]);
                    ind = i;
                }
            }
            nums[ind]*=multiplier;
        }
        return nums;
    }
};
