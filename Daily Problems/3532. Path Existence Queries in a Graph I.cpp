class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> comp(n,-1);
        int compId = 0;
        comp[0] = compId;

        for(int i = 1;i < n;i++){
            if(nums[i] - nums[i-1] > maxDiff)
                compId++;
            comp[i] = compId;
        }

        vector<bool> ans;
        for(auto &query : queries){
            int u = query[0];
            int v = query[1];
            ans.push_back(comp[u] == comp[v]);
        }
        return ans;
    }
};
