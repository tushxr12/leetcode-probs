class Solution {
public:
    int m,n;
    int dp[101][101][201];

    bool solve(int i,int j, int openCount, vector<vector<char>> &grid)
    {
        openCount += (grid[i][j] == '(') ? 1 : -1;

        if(openCount < 0)
            return false;
        
        if(i == m - 1 && j == n -1)
        {
            return (openCount == 0);
        }

        if(dp[i][j][openCount] != -1)
            return dp[i][j][openCount];

        // Right
        if(j + 1 < n){
            if(solve(i,j+1,openCount,grid))
                return dp[i][j][openCount] = true;
        }

        // Bottom
        if(i + 1 < m){
            if(solve(i+1,j,openCount,grid))
                return dp[i][j][openCount] = true;
        }
        return dp[i][j][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if((m+n-1)%2 == 1)
            return false;
        
        if(grid[0][0] == ')' || grid[m-1][n-1] == '(')
            return false;
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0,0,0,grid);
    }
};
