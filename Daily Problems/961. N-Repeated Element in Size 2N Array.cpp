class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int rep = n/2;

        unordered_map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;
        
        for(auto i : mpp)
            if(i.second == rep)
                return i.first;
        
        return -1;
    }
};
