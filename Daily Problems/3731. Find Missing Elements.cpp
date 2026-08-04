class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = *min_element(begin(nums), end(nums));
        int maxi = *max_element(begin(nums), end(nums));
        set<int> st(begin(nums), end(nums));

        vector<int> ans;
        for(int i = mini + 1;i <= maxi-1;i++)
        {
            if(st.find(i) == st.end())
                ans.push_back(i);
        }
        return ans;
    }
};
