class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0, pairs = 0;
        int i = 0,j = 0, n = nums.size();
        unordered_map<int,int> mpp;
        while(j < n)
        {
            pairs += mpp[nums[j]];
            mpp[nums[j]]++;

            while(pairs >= k)
            {
                ans += (n - j);
                mpp[nums[i]]--;
                pairs -= mpp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};
