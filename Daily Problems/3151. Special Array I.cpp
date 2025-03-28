class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return true;
        
        for(int i = 0;i < n - 1;i++)
        {
            if(nums[i]%2 == nums[i + 1]%2)
                return false;
        }
        return true;
    }
};

//Bits approach
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n - 1;i++)
        {
            if((nums[i]&1)^(nums[i + 1]&1) == 0)
                return false;
        }
        return true;
    }
};
