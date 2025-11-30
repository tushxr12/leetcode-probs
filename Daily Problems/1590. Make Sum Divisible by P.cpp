class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long sum = 0;
        for(auto i : nums)
            sum += (i%p);
        if(sum%p == 0)
            return 0;
        
        int target = sum%p;
        
        map<int,int> mpp;
        mpp[0] = -1;
        
        int ans = n;
        int currSum = 0;
        for(int j = 0;j <n;j++){
            currSum = (currSum + nums[j])%p;

            int remain = (currSum - target + p)%p;

            if(mpp.find(remain) != mpp.end()){
                ans = min(ans, j - mpp[remain]);
            }

            mpp[currSum] = j;
        }
        return (ans == n) ? -1 : ans;
    }
};
