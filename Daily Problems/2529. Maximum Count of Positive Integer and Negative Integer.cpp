class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pc = 0, nc = 0;
        for(auto i : nums)
            if(i < 0)
                nc++;
            else if(i > 0) 
                pc++;

        return (pc > nc) ? pc : nc;
    }
};
