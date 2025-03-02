//Recur
class Solution {
private:
    int f(int low,int high,int zero,int one,int len)
    {
        if(len > high)
            return 0;
        
        int zeroLen = len + zero;
        int oneLen = len + one;
        int zeroCount = (zeroLen >= low && zeroLen <= high) ? 1 : 0;
        int oneCount = (oneLen >= low && oneLen <= high) ? 1 : 0;
        int zeroRes = zeroCount + f(low, high,zero, one, zeroLen);
        int oneRes = oneCount + f(low, high, zero,one, oneLen);
        return (zeroRes + oneRes);
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        return f(low, high, zero, one, 0);
    }
};

//Memoization
class Solution {
private:
    int mod = 1e9 + 7;
    int f(int low,int high, int zero,int one,int len, vector<int> &dp)
    {
        if(len > high)
            return 0;
        
        if(dp[len] != -1)
            return dp[len];
        
        int zeroLen = len + zero;
        int oneLen = len + one;
        int zeroCount = (zeroLen >= low && zeroLen <= high) ? 1 : 0;
        int oneCount = (oneLen >= low && oneLen <= high) ? 1 : 0;
        int res = (zeroCount + f(low, high, zero, one, zeroLen, dp) + oneCount + f(low, high, zero, one, oneLen, dp))%mod;
        return dp[len] = res;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int maxLen = high + max(zero , one);
        vector<int> dp(maxLen + 1,-1);
        return f(low, high, zero,one ,0,dp);
    }
};

//Tabulation
class Solution {
private:
    int mod = 1e9 + 7;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int maxLen = high + max(zero , one);
        vector<int> dp(maxLen + 1,-0);
        for(int len = high ; len >= 0;len--)
        {
            int zeroLen = len + zero;
            int oneLen = len + one;
            int zeroCount = (zeroLen >= low && zeroLen <= high) ? 1 : 0;
            int oneCount = (oneLen >= low && oneLen <= high) ? 1 : 0;
            int res = (zeroCount + dp[zeroLen] + oneCount + dp[oneLen])%mod;
            dp[len] = res % mod;
        }
        return dp[0];
    }
};
