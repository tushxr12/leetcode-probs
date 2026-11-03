class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(begin(nums), end(nums));
        int ans = 0;
        for(auto i : nums)
            ans += (maxi - i);
        return ans;
    }
};
