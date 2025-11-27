// Brute

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = INT_MIN;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            long long currSum = 0;
            for(int j = i;j < n;j++){
                currSum += nums[j];
                int sz = j - i + 1;

                if(sz%k == 0){
                    ans = max(ans, currSum);
                }
            }
        }
        return ans;
    }
};
