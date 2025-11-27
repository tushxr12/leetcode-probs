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


// Optimal (Kadanes + Prefix Sum)
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        int n = nums.size();

        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        for(int i = 1;i < n;i++)
            prefSum[i] = prefSum[i-1] + nums[i];
        
        for(int start = 0; start < k;start++){
            long long currSum = 0;

            int i = start;

            while(i < n && i + k - 1 < n){
                int j = i + k - 1;

                long long subarraySum = prefSum[j] - ((i > 0) ? prefSum[i - 1] : 0);
                currSum = max(subarraySum, currSum + subarraySum);
                ans = max(ans, currSum);

                i += k;
            }
        }


        return ans;
    }
};
