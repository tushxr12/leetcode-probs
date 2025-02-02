class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        for(int r = 0; r < nums.size();r++)
        {
            bool isMatch = true;
            for(int i = 0;i < nums.size();i++)
            {
                if(nums[(r + i)%nums.size()] != sorted[i])
                {
                    isMatch = false;
                    break;
                }
            }
            if(isMatch)
                return true;
        }
        
        return false;
    }
};
