class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int res = 0, curr = 0, S = accumulate(begin(nums), end(nums), 0);

        for(int i = 0;i <n;i++){
            curr += nums[i];

            int left = curr;
            int right = S - left;

            if(nums[i] != 0)
                continue;
            
            if(left == right)
                res += 2;
            
            if(abs(left - right) == 1)
                res += 1;
        }

        return res;
    }
};
