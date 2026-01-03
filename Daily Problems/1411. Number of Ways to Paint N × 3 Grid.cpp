class Solution {
public:
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY" , "YRY", "GRY", "GYR", "GRG", "GYG"};
    int mod = 1e9 + 7;

    int solve(int n,int prev, vector<vector<int>> &dp)
    {
        if(n == 0)
            return 1;
        
        if(dp[n][prev] != -1)
            return dp[n][prev];
        
        int result = 0;
        string last = states[prev];

        for(int curr = 0; curr < 12;curr++)
        {
            if(curr == prev)
                continue;
            
            string currPat = states[curr];
            bool conflict = false;

            for(int col = 0; col < 3; col++){
                if(currPat[col] == last[col]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                result = (result + solve(n-1, curr,dp)) % mod;
            }
        }

        return dp[n][prev] = result;
    }
    int numOfWays(int n) {
        int result = 0; 
        vector<vector<int>> dp(n, vector<int>(12,-1));

        for(int i = 0;i < 12;i++){
            result = (result + solve(n-1,i,dp))%mod;
        }

        return result;
    }
};
