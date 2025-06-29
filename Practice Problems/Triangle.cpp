//Recursion
class Solution {
private:
    int func(int i,int j,int n, vector<vector<int>> &triangle)
    {
        if(i == n - 1)
            return triangle[i][j];
        
        int down = triangle[i][j] + func(i + 1,j, n,triangle);
        int dg = triangle[i][j] + func(i + 1,j + 1,n,triangle);

        return min(down, dg);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return func(0,0,n,triangle);
    }
};

//Memoization
//TC->O(N*N)
//SC->O(N*N)
class Solution {
private:
    int func(int i,int j,int n, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if(i == n - 1)
            return triangle[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int down = triangle[i][j] + func(i + 1,j, n,triangle,dp);
        int dg = triangle[i][j] + func(i + 1,j + 1,n,triangle,dp);

        return dp[i][j] = min(down, dg);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return func(0,0,n,triangle,dp);
    }
};
