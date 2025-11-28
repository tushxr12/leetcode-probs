class Solution {
private:
    int dfs(int curr, int parent, unordered_map<int, vector<int>> &adj, vector<int> &values, int k)
    {
        int sum = values[curr];

        for(auto &i : adj[curr]){
            if(i != parent){
                sum += dfs(i, curr, adj, values, k);
                sum %= k;
            }
        }

        sum %= k;
        if(sum == 0){
            count++;
        }
        return sum;
    }
public:
    int count;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        count = 0;

        dfs(0, -1, adj, values, k);
        return count;
    }
};
