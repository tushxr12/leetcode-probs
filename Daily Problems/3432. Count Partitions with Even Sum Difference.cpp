class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total_sum = accumulate(begin(nums), end(nums), 0);
        if(total_sum%2)
            return 0;
        
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i < n - 1;i++){
            int leftSum = nums[i];
            int rightSum = (total_sum - leftSum);
            if((leftSum-rightSum)%2 == 0)
                ans++;
        }
        return ans;
    }
};
