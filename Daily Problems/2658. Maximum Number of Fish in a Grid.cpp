class Solution {
private:
    int rows, cols;
    int dfs(int r,int c, vector<vector<int>> &grid)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0)
            return 0;
        
        int ans = grid[r][c];
        grid[r][c] = 0;
        ans += dfs(r - 1,c,grid) + dfs(r,c + 1,grid) + dfs(r + 1,c,grid) + dfs(r, c - 1,grid);
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        int ans = 0;
        for(int i = 0;i < rows;i++)
        {
            for(int j = 0;j < cols;j++)
            {
                if(grid[i][j] != 0)
                {
                    ans = max(ans, dfs(i,j,grid));  
                }
            }
        }
        return ans;
    }
};
