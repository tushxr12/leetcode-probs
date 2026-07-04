class Solution {
private:
    void dfs(int node, vector<bool> &visited, unordered_map<int, vector<pair<int,int>>> &adj, int& res)
    {
        visited[node] = true;

        for(auto &it : adj[node])
        {
            int v = it.first;
            int d = it.second;

            res = min(res, d);

            if(!visited[v]){
                dfs(v, visited, adj, res);
            }
        }
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for(auto &vec : roads)
        {
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> visited(n, false);
        int res = INT_MAX;
        dfs(1,visited,adj,res);
        return res;
    }
};
