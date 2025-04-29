class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxElement = *max_element(nums.begin(), nums.end());
        int countMax = 0;

        int i = 0,j = 0;
        int n = nums.size();

        while(j < n)
        {
            if(nums[j] == maxElement)
                countMax++;
            
            while(countMax >= k)
            {
                ans += (n - j);

                if(nums[i] == maxElement)
                {
                    countMax--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
