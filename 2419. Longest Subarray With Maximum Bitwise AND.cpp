class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0, curr = 0, ans = 0;
        for(auto i : nums)
        {
            if(i > maxi)
            {
                maxi = i;
                curr = 0;
                ans = 0;
            }

            if(i == maxi)
            {
                curr++;
            }
            else
            {
                curr=0;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};