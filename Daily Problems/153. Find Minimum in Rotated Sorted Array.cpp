class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums[0];
    }
};
