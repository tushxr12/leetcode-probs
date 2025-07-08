//Recursion
class Solution {
private:
    int solve(int index, vector<vector<int>> &events, int n, int k)
    {
        if(index >= n || k == 0)
            return 0;
        
        int start = events[index][0];
        int end = events[index][1];
        int value = events[index][2];

        int notTake = solve(index + 1, events, n, k);

        int j = index + 1;
        for(;j < n;j++)
            if(events[j][0] > end)
                break;
        
        int take = value + solve(j, events, n , k - 1);
        return max(take, notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        return solve(0,events,n, k);
    }
};

//Memoization
class Solution {
private:
    int solve(int index, vector<vector<int>> &events, int n, int k, vector<vector<int>> &dp)
    {
        if(index >= n || k == 0)
            return 0;
        
        if(dp[index][k] != -1)
            return dp[index][k];
        
        int start = events[index][0];
        int end = events[index][1];
        int value = events[index][2];

        int notTake = solve(index + 1, events, n, k, dp);

        int j = index + 1;
        for(;j < n;j++)
            if(events[j][0] > end)
                break;
        
        int take = value + solve(j, events, n , k - 1, dp);
        return dp[index][k] = max(take, notTake);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1,-1));
        return solve(0,events,n, k, dp);
    }
};
