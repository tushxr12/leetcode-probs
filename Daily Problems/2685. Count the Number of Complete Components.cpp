// Using DFS
class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>> &adj, vector<bool> &visited, int &v, int &e)
    {
        visited[node] = true;
        v++;
        e += adj[node].size();

        for(auto &ngbr : adj[node])
        {
            if(!visited[ngbr])
            {
                dfs(ngbr, adj, visited,v,e);
            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int ans = 0;

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
            {
                int v = 0, e = 0;
                dfs(i, adj, visited, v, e);
                if((v*(v-1) == e))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

// Using BFS
class Solution {
public:
    void bfs(int node, unordered_map<int,vector<int>> &adj, vector<bool> &visited, int &v, int &e)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty())
        {
            int sz = q.size();

            for(int i = 0;i < sz;i++)
            {
                auto node = q.front();
                q.pop();

                v++;
                e += adj[node].size();

                for(auto &ngbr : adj[node])
                {
                    if(!visited[ngbr])
                    {
                        visited[ngbr] = true;
                        q.push(ngbr);
                    }
                }

            }
        }

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        int ans = 0;

        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        for(int i = 0;i < n;i++)
        {
            if(!visited[i])
            {
                int v = 0, e = 0;
                bfs(i, adj, visited, v, e);
                if((v*(v-1) == e))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};
