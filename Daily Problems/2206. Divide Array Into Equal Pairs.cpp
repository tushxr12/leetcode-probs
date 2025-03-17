class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> mpp;
        for(auto i : nums)
            mpp[i]++;
        
        int n = nums.size();
        int pairs = n/2;

        for(auto i : mpp)
            if(i.second%2 != 0)
            {
                return false;
            } 

        return true;
    }
};
