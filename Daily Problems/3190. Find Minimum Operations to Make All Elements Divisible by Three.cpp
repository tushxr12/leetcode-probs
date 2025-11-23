class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(auto i : nums)
            if(i%3 != 0)
                ops++;
        return ops;
    }
};
