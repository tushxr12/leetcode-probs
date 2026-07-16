class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;

        int n = nums.size();
        vector<long long> prefixGcd(n);
        int currMax = nums[0];
        
        for(int i = 0;i < n;i++){
            currMax = max(currMax, nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], (long long)currMax);
        }
        
        sort(begin(prefixGcd) , end(prefixGcd));

        long long low = 0, high = prefixGcd.size() - 1;
        while(low < high){
            ans += __gcd(prefixGcd[low], prefixGcd[high]);
            low++;high--;
        }
        return ans;
    }
};
