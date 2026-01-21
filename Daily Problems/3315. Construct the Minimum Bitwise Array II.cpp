class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 2)
            {
                ans.push_back(-1);
                continue;
            }
            
            bool found = false;
            for(int j = 1;j < 32;j++)
            {
                if((nums[i] & (1 << j)) > 0) // jth bit is set
                {
                    continue;
                }

                int prev = j - 1;
                // set it to 0
                int x = (nums[i] ^ (1 << (j-1)));
                ans.push_back(x);
                found = true;
                break;
            }
            if(!found)
                ans.push_back(-1);
        }
        return ans;
    }
};  
