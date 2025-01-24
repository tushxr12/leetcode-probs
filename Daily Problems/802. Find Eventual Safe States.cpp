class Solution {
private:
    bool dfs(int node, vector<vector<int>> &graph, map<int,bool> &mpp)
    {
        if(mpp.find(node) != mpp.end())
        {
            return mpp[node];
        }

        mpp[node] = false;
        for(auto neighbor : graph[node])
        {
            if(dfs(neighbor, graph, mpp) == false)
            {
                return false;
            }
        }
        mpp[node] = true;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        map<int,bool> mpp;
        vector<int> ans;
        for(int i = 0;i < n;i++)
        {
            if(dfs(i, graph, mpp))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
