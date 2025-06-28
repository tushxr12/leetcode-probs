//Recursion
class Solution {
private:
    int func(int i, int j, int n, int m)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        //Top
        int top = func(i - 1,j,n,m);

        //Left
        int left = func(i, j - 1,n,m);

        return (top + left);
    }
public:
    int uniquePaths(int m, int n) {
        return func(m - 1,n - 1,m,n);
    }
};

//Memoization
//TC->O(M*N)
//SC->O((N-1)+(M-1))+O(M*N)
class Solution {
private:
    int func(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        //Top
        int top = func(i - 1,j,n,m,dp);

        //Left
        int left = func(i, j - 1,n,m,dp);

        return dp[i][j] = (top + left);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1,n - 1,m,n, dp);
    }
};

//Tabulation
//TC->O(N*M)
//SC->O(N*M)
class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        // dp[0][0] = 1;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                int top = 0, left = 0;

                //Top 
                if(i > 0)
                    top = dp[i - 1][j];

                //Left
                if(j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = (top + left);
            }
        }
        return dp[n - 1][m - 1];
    }
};

//Space Optimization
//TC->O(N*M)
//SC->O(M)
class Solution {
public:
    int uniquePaths(int n, int m) {
        // dp[0][0] = 1;
        vector<int> prev(m, 0);

        for(int i = 0;i < n;i++)
        {
            vector<int> temp(m, 0);
            for(int j = 0;j < m;j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int top = 0, left = 0;

                //Top 
                if(i > 0)
                    top = prev[j];

                //Left
                if(j > 0)
                    left = temp[j - 1];

                temp[j] = (top + left);
            }
            prev = temp;
        }
        return prev[m - 1];
    }
};
