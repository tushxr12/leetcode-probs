// Recursion
class Solution {
private:
    int solve(int i, int j,int n,int m, vector<vector<int>> &matrix){
        if(i >= n || j >= m)
            return 0;
        
        if(matrix[i][j] == 0)
            return 0;
        
        int right = solve(i,j+1,n,m,matrix);
        int diag = solve(i+1,j+1,n,m,matrix);
        int bottom = solve(i+1,j,n,m,matrix);

        return 1 + min({right, diag, bottom});
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                res += solve(i,j,n,m,matrix);
            }
        }
        return res;
    }
};

//Memoization
class Solution {
private:
    int solve(int i, int j,int n,int m, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(i >= n || j >= m)
            return 0;
        
        if(matrix[i][j] == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solve(i,j+1,n,m,matrix,dp);
        int diag = solve(i+1,j+1,n,m,matrix,dp);
        int bottom = solve(i+1,j,n,m,matrix,dp);

        return dp[i][j] = 1 + min({right, diag, bottom});
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1,-1));

        int res = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == 1)
                    res += solve(i,j,n,m,matrix,dp);
            }
        }
        return res;
    }
};
