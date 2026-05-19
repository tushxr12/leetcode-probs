class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        for(auto i : nums1)
            st.insert(i);
        
        for(auto i : nums2){
            if(st.find(i) != st.end())
                return i;
        }
        return -1;
    }
};
