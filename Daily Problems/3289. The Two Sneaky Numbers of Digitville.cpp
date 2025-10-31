class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;
        
        for(auto i : mpp)
            if(i.second > 1)
                ans.push_back(i.first);
        return ans;
    }
};
