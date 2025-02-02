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

//Better
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return true;
        int ic = 0;
        for(int i = 1;i <n;i++)
        {
            if(nums[i - 1] > nums[i])
            {
                ic++;
            }
        }
        if(nums[0] < nums[n - 1])
            ic++;
        return (ic <= 1);
    }
};
