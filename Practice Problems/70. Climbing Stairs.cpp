//Recursion
//TC->O(2^N)
//SC->O(N)
class Solution {
private:
    int func(int ind)
    {
        if(ind <= 1)
            return 1;
        
        int poss1 = func(ind - 1);
        int poss2 = func(ind - 2);
        return (poss1 + poss2);
    }
public:
    int climbStairs(int n) {
        return func(n);
    }
};

//Memoization
//TC->O(N)
//SC->O(N)+O(N)
class Solution {
private:
    int func(int ind, vector<int> &dp)
    {
        if(ind <= 1)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        int poss1 = func(ind - 1,dp);
        int poss2 = func(ind - 2,dp);
        return dp[ind] = (poss1 + poss2);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1,-1);
        return func(n, dp);
    }
};

//Tabulation
//TC->O(N)
//SC->O(N)
class Solution {
public:
    int climbStairs(int n) {

        if(n <= 1)
            return 1;
        
        vector<int> dp(n + 1,-1);
        dp[0] = 1, dp[1] = 1;
        
        for(int i = 2;i <= n;i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

//Space optimization
//TC->O(N)
//SC->O(1)
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1)
            return 1;
            
        int secondPrev = 1, prev = 1;
        
        for(int i = 2;i <= n;i++)
        {
            int current = prev + secondPrev;
            secondPrev = prev;
            prev = current;
        }
        return prev;
    }
};
