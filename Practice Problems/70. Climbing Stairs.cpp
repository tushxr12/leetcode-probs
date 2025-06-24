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
