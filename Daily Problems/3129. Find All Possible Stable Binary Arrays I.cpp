class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {
        
        memset(dp, 0, sizeof(dp));

        dp[0][0][0] = 1;
        dp[0][0][1] = 1;

        

        for(int onesLeft = 0; onesLeft <= one; onesLeft++){
            for(int zeroesLeft = 0; zeroesLeft <= zero; zeroesLeft++)
            {
                if(onesLeft == 0 && zeroesLeft == 0)
                    continue;

                int res = 0;
                for(int len = 1; len <= min(zeroesLeft, limit); len++){
                    res = (res + dp[onesLeft][zeroesLeft - len][0])%mod;
                }
                dp[onesLeft][zeroesLeft][1] = res;

                res = 0;
                for(int len = 1; len <= min(onesLeft, limit); len++){
                    res = (res + dp[onesLeft - len][zeroesLeft][1])%mod;
                }
                dp[onesLeft][zeroesLeft][0] = res;
            }
        }

        int startWithZero = dp[one][zero][1];
        int startWithOne = dp[one][zero][0];

        return (startWithZero + startWithOne) % mod;
    }
};
