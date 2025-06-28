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
