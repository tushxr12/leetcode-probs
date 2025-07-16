class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evenCount = 0, oddCount = 0, alternating = 1;

        for(auto i : nums)
            if(i%2)
                oddCount++;
            else
                evenCount++;
        
        int parity = nums[0]%2;

        for(int i = 1;i < n;i++)
        {
            int currParity = nums[i]%2;
            if(currParity != parity)
            {
                alternating++;
                parity = currParity;
            }
        }
        return max({evenCount, oddCount, alternating});
    }
};
