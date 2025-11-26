// Brute
class Solution {
private:
    int mod = 1e9 + 7;

    int solve(int row, int col, int currSum, int k, int n,int m, vector<vector<int>>& grid)
    {
        if(row >= n || col >= m)
            return 0;
            
        if(row == n - 1 && col == m - 1){
            return (currSum + grid[n-1][m-1])%k == 0 ? 1 : 0;
        }

        int down = solve(row+1,col,currSum + grid[row][col],k,n,m,grid);
        int right = solve(row,col + 1,currSum+grid[row][col],k,n,m,grid);

        return (down + right)%mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        return solve(0,0,0,k,n,m,grid);
    }
};
