class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int res = INT_MAX;

        for(int i = 0;i < n;i++){
            if(target == nums[i]){
                res = min(res, abs(i - start));
            }
        }

        return res;
    }
};
