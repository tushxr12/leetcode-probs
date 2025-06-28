//Recursion
class Solution {
private:
    int func(int i,int j, int n,int m, vector<vector<int>> &matrix)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        
        int top = func(i - 1,j,n,m,matrix);

        int left = func(i, j -1,n,m,matrix);

        return (top + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(matrix[0][0] == 1 || matrix[n-1][m-1] == 1)
            return 0;
        return func(n -1,m -1, n,m, matrix);
    }
};

//Memoization
class Solution {
private:
    int func(int i,int j, int n,int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int top = func(i - 1,j,n,m,matrix,dp);

        int left = func(i, j -1,n,m,matrix,dp);

        return dp[i][j] = (top + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(matrix[0][0] == 1 || matrix[n-1][m-1] == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return func(n -1,m -1, n,m, matrix,dp);
    }
};
