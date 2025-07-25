class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result = 0, maxNeg = INT_MIN;
        set<int> st;
        for(auto i : nums)
            if(i > 0)
                st.insert(i);
            else
                maxNeg = max(maxNeg, i);
            
        for(auto i : st)
            result += i;
        return result == 0 ? maxNeg : result;
    }
};
