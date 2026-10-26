class Solution {
public:
    int m,n;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    long long dfs(vector<vector<int>>& grid, int i, int j)
    {
        long long sum = grid[i][j];
        grid[i][j] = 0;

        for(auto &dir : dirs)
        {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0)
            {
                sum += dfs(grid, i_,j_);
            }
        }
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] != 0)
                {
                    long long sum = dfs(grid,i,j);
                    if(sum%k == 0)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;    
    }
};
