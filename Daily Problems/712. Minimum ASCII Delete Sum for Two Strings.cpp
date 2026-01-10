class Solution {
public:
    int solve(int i,int j,int n,int m,string&s1, string &s2, vector<vector<int>> &dp)
    {
        if(i >= n && j >= m)
        {
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(i >= n)
            return dp[i][j] = s2[j] + solve(i,j+1,n,m,s1,s2,dp);
        
        if(j >= m)
            return dp[i][j] = s1[i] + solve(i+1,j,n,m,s1,s2,dp);
        
        if(s1[i] == s2[j])
            return dp[i][j] = 0 + solve(i+1,j+1,n,m,s1,s2,dp);
        
        // Two possibilities
        int delete_s1_i = s1[i] + solve(i+1,j,n,m,s1,s2,dp);
        int delete_s2_j = s2[j] + solve(i,j+1,n,m,s1,s2,dp);

        return dp[i][j] = min(delete_s1_i, delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(0,0,n,m,s1,s2,dp);
    }
};
