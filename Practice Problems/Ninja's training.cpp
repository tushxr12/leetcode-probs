//Recursion
//TC->O(3^N)
//SC->O(N)
class Solution {
private:
    int func(int day, int last, vector<vector<int>> &nums)
    {
        if(day == 0)
        {
            int maxi = 0;
            for(int task = 0; task < 3;task++)
            {
                if(task != last)
                    maxi = max(maxi, nums[day][task]);
            }
            return maxi;
        }

        int maxi = 0;
        for(int task = 0; task < 3;task++)
        {
            if(task != last){
                int points = nums[day][task] + func(day - 1,task,nums);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return func(n - 1,3,matrix);
    }
};

//Memoization
//TC->O(N*4*3)
//SC->O(N)+O(N*4)
class Solution {
private:
    int func(int day, int last, vector<vector<int>> &nums, vector<vector<int>> &dp)
    {
        if(day == 0)
        {
            int maxi = 0;
            for(int task = 0; task < 3;task++)
            {
                if(task != last)
                    maxi = max(maxi, nums[day][task]);
            }
            return maxi;
        }

        if(dp[day][last] != -1)
        {
            return dp[day][last];
        }

        int maxi = 0;
        for(int task = 0; task < 3;task++)
        {
            if(task != last){
                int points = nums[day][task] + func(day - 1,task,nums, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return func(n - 1,3,matrix,dp);
    }
};
