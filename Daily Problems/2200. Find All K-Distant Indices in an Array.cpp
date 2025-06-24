class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        set<int> st;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            int currNumber = nums[i];
            if(currNumber == key)
            {
                for(int j = 0;j < n;j++)
                {
                    if(abs(i - j) <= k)
                        st.insert(j);
                }
            }
        }
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
