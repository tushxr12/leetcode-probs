class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1)
            return 0;
        sort(begin(nums), end(nums));
        int n = nums.size();
        int i = 0,j = k-1;
        int ans = INT_MAX;
        while(j < n)
        {
            int curr = nums[j] - nums[i];
            ans = min(ans, curr);
            j++;i++;
        }

        return ans;
    }
};
