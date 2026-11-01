class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mini = *min_element(begin(nums), end(nums));

        for(auto i : nums)
        {
            ans += (i- mini);
        }
        return ans;
    }
};
