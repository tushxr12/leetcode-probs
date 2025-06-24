//Recursion
//TC->O(2^N)
//SC->O(N)
class Solution {
private:
    int f(int ind, vector<int> &heights)
    {
        if(ind == 0)
            return 0;
        
        int poss1 = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
        int poss2 = INT_MAX;

        if(ind > 1)
            poss2 = min(poss2,f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]));

        return min(poss1, poss2);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return f(n - 1, heights);
    }
};

//Memoization
//TC->O(N)
//SC->O(N) + O(N)
class Solution {
private:
    int f(int ind, vector<int> &heights, vector<int> &dp)
    {
        if(ind == 0)
            return 0;
        
        if(dp[ind] != -1)
            return dp[ind];

        int poss1 = f(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
        int poss2 = INT_MAX;

        if(ind > 1)
            poss2 = min(poss2,f(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]));

        return dp[ind] = min(poss1, poss2);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, - 1);
        return f(n - 1, heights, dp);
    }
};

//Tabulation
//TC->O(N)
//SC->O(N)
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int> dp(n, - 1);
        dp[0] = 0;

        for(int i = 1;i < n;i++)
        {
            int poss1 = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int poss2 = INT_MAX;
            if(i > 1)
                poss2 = min(poss2,dp[i - 2] + abs(heights[i] - heights[i - 2]));
            
            dp[i] = min(poss1, poss2);
        }
        return dp[n - 1];
    }
};

//Space Optimization
//TC->O(N)
//SC->O(1)
class Solution {
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        int prev = 0, secondPrev = 0;

        for(int i = 1;i < n;i++)
        {
            int poss1 = prev + abs(heights[i] - heights[i - 1]);
            int poss2 = INT_MAX;
            if(i > 1)
                poss2 = min(poss2,secondPrev + abs(heights[i] - heights[i - 2]));
            
            int curr = min(poss1, poss2);
            secondPrev = prev;
            prev = curr;
        }
        return prev;
    }
};
