class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> st(begin(nums), end(nums));

        if(st.find(original) == st.end()){
            return original;
        }

        while(st.find(original) != st.end()){
            original *= 2;
        }
        return original;
    }
};
