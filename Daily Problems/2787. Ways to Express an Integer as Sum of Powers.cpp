// Brute
class Solution {
private:
    int solve(int n,int num,int x){
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n)
            return 0;
        
        int take = solve(n - currPowerValue, num + 1,x);
        int skip = solve(n, num + 1, x);

        return (take + skip);
    }
public:
    int numberOfWays(int n, int x) {
        return solve(n, 1, x);
    }
};

// Using DP
class Solution {
private:
    int solve(int n,int num,int x, vector<vector<int>> &dp){
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n)
            return 0;

        if(dp[n][num] != -1)
            return dp[n][num];

        int take = solve(n - currPowerValue, num + 1,x, dp);
        int skip = solve(n, num + 1, x, dp);

        return dp[n][num] = (take + skip)%mod;
    }
public:
    int mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int>(301, -1));
        return solve(n, 1, x, dp);
    }
};
