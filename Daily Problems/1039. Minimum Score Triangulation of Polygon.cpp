class Solution {
private:
    int solve(vector<int> &values, int i,int j, int dp[51][51]){
        if(j - i + 1 < 3)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res = INT_MAX;
        for(int k = i + 1;k < j;k++){
            int wt = (values[i] * values[j] * values[k]) + solve(values,i,k,dp) + solve(values,k,j,dp);
            res = min(res, wt);
        }
        return dp[i][j] = res;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        int dp[51][51];
        memset(dp,-1,sizeof(dp));
        return solve(values, 0, n - 1, dp); 
    }
};
