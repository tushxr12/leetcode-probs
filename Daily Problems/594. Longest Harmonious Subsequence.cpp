class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(auto i : nums) 
            mpp[i]++;
        
        int ans = 0;
        
        for(auto i : nums)
        {
            int mini = i;
            int maxi = i + 1;

            if(mpp.contains(maxi))
            {
                ans = max(ans, mpp[mini] + mpp[maxi]);
            } 
        }
        return ans;
    }
};
