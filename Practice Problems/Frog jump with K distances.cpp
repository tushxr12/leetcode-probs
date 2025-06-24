//Recursion
//TC->O(K^N)
//SC->O(N)
class Solution {
private:
    int func(int ind, vector<int> &heights, int k)
    {
        if(ind == 0)
            return 0;
        
        int minSteps = INT_MAX;

        for(int j = 1;j <= k;j++)
        {
            if((ind - j) >=0 )
            {
                int jump = func(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);

                minSteps = min(minSteps, jump);
            }
        }
        return minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return func(n - 1, heights, k);
    }
};

//Memoization
//TC->O(N*K)
//SC->O(N)
class Solution {
private:
    int func(int ind, vector<int> &heights, int k, vector<int> &dp)
    {
        if(ind == 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int minSteps = INT_MAX;

        for(int j = 1;j <= k;j++)
        {
            if((ind - j) >=0 )
            {
                int jump = func(ind - j, heights, k, dp) + abs(heights[ind] - heights[ind - j]);
                minSteps = min(minSteps, jump);
            }
        }
        return dp[ind] = minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        return func(n - 1, heights, k, dp);
    }
};

//Tabulation
//TC->O(N*K)
//SC->O(N)
class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int ind = 1; ind < n;ind++)
        {
            int minSteps = INT_MAX;

            for(int j = 1;j <= k;j++)
            {
                if((ind - j) >=0 )
                {
                    int jump = dp[ind - j] + abs(heights[ind] - heights[ind - j]);
                    minSteps = min(minSteps, jump);
                }
            }

            dp[ind] = minSteps;
        }
        return dp[n - 1];
    }
};
