class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = *max_element(begin(nums), end(nums));
        long long mini = *min_element(begin(nums), end(nums));

        long long ans = 1LL*(maxi - mini)*k;
        return ans;
    }
};
