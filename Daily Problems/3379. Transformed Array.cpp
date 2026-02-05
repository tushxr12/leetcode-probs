class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        for(int i = 0;i < n;i++)
        {
            int shifts = nums[i]%n;
            int newIndex = (i + nums[i])%n;

            if(newIndex < 0)
                newIndex += n;
            
            res[i] = nums[newIndex];
        }
        return res;
    }
};
