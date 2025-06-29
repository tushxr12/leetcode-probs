//Recursion
class Solution {
private:
    int func(int i,int j, int n, int m, vector<vector<int>> &matrix)
    {
        if(j < 0 || j >= m)
            return 1e9;
        
        if(i == 0)
            return matrix[i][j];

        int top = matrix[i][j] + func(i - 1,j,n,m,matrix);
        int ld = matrix[i][j] + func(i-1,j-1,n,m,matrix);
        int rd = matrix[i][j] + func(i-1,j+1,n,m,matrix);

        return min({top, rd, ld});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;

        for(int j = 0;j < m;j++)
        {
            mini = min({mini, func(n-1,j,n,m,matrix)});
        }

        return mini;
    }
};

//Memoization
//TC->O(N*M)
//SC->O(N*M)
class Solution {
private:
    int func(int i,int j, int n, int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j < 0 || j >= m)
            return 1e9;
        
        if(i == 0)
            return matrix[i][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int top = matrix[i][j] + func(i - 1,j,n,m,matrix,dp);
        int ld = matrix[i][j] + func(i-1,j-1,n,m,matrix,dp);
        int rd = matrix[i][j] + func(i-1,j+1,n,m,matrix,dp);

        return dp[i][j] = min({top, rd, ld});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));

        for(int j = 0;j < m;j++)
        {
            mini = min({mini, func(n-1,j,n,m,matrix,dp)});
        }

        return mini;
    }
};

//Tabulation
//TC->O(N*M)
//SC->O(N*M)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));

        for(int j = 0;j < m;j++)
            dp[0][j] = matrix[0][j];

        
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                int top = matrix[i][j] + dp[i-1][j];

                int ld = matrix[i][j];
                if(j - 1 >= 0)
                    ld += dp[i-1][j-1];
                else
                    ld += 1e9;
                int rd = matrix[i][j];
                if(j + 1 < m)
                    rd += dp[i-1][j+1];
                else
                    rd += 1e9;

                dp[i][j] = min({top, rd, ld});
            }
        }

        for(int j = 0;j < m;j++)
        {
            mini = min({mini, dp[n-1][j]});
        }

        return mini;
    }
};
