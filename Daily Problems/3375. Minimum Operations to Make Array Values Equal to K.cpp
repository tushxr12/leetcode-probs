class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        int n = nums.size();
        for(auto i : nums)
        {
            if(i < k)
                return -1;
            else if(i > k)
                st.insert(i);
        }
        return st.size();
    }
};
