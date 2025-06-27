//Recursion
//TC->O(2^N) + O(2^N)
//SC->O(4N)
class Solution {
private:
    int func(int index, vector<int> &nums)
    {
        if(index == 0)
            return nums[0];
        
        if(index < 0)
            return 0;
        
        int pick = INT_MIN;
        
        if(index > 1)
            pick = max(pick,nums[index] + func(index - 2, nums));

        int notPick = 0 + func(index - 1, nums);

        return max(pick, notPick);
    }
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> v1,v2;

        for(int i = 0;i < n;i++)
        {
            if(i != 0)  
                v1.push_back(money[i]);
            if(i != n - 1)
                v2.push_back(money[i]);
        }

        int ans1 = func(n - 1, v1);
        int ans2 = func(n - 1, v2);

        return max(ans1, ans2);
    }
};

//Memoization
//TC->O(2N)
//SC->O(5N)
class Solution {
private:
    long long int func(int index, vector<int> &nums, vector<int> &dp)
    {
        if(index == 0)
            return nums[0];
        
        if(index < 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int pick = nums[index] + func(index - 2, nums, dp);

        int notPick = 0 + func(index - 1, nums, dp);

        return dp[index] = max(pick, notPick);
    }
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();

        if(n == 1)
            return money[0];
            
        vector<int> v1,v2;
        vector<int> dp1(n, -1), dp2(n, -1);

        for(int i = 0;i < n;i++)
        {
            if(i != 0)  
                v1.push_back(money[i]);
            if(i != n - 1)
                v2.push_back(money[i]);
        }

        long long int ans1 = func(n - 2, v1, dp1);
        long long int ans2 = func(n - 2, v2, dp2);

        return max(ans1, ans2);
    }
};
