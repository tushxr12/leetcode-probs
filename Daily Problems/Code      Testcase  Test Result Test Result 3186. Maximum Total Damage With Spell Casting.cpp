class Solution {
public: 
    typedef long long ll;
    unordered_map<ll,ll> mpp;
    vector<ll> dp;
    int n;

    ll solve(int index, vector<ll> &nums)
    {
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1)
            return dp[index];

        ll nextSafeIndex = lower_bound(begin(nums)+index + 1, end(nums), nums[index] + 3) - begin(nums);
        ll pick = nums[index]*mpp[nums[index]] + solve(nextSafeIndex, nums);

        ll notPick = solve(index + 1, nums);

        return dp[index] = max(pick, notPick);
    }

    long long maximumTotalDamage(vector<int>& power) {
        for(auto i : power){
            mpp[i]++;
        }

        vector<ll> nums(mpp.size());
        for(auto &it: mpp){
            nums.push_back(it.first);
        }

        sort(begin(nums), end(nums));
        n = nums.size();

        dp.assign(n,-1);

        return solve(0,nums);
    }
};
