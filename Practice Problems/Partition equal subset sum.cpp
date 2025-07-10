//Recursion
class Solution{
private:
    bool func(int index, vector<int> &arr, int n, int target)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return (target == arr[0]);
        
        //Not pick
        bool notPick = func(index - 1, arr, n, target);

        //Pick 
        bool pick = false;
        if(arr[index] <= target)
            pick = func(index - 1, arr, n, target - arr[index]);

        return (pick || notPick);
    }
public:
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for(auto i : arr)
            sum += i;
        
        if(sum%2)
            return false;
        return func(n - 1,arr,n,sum/2);
    }
};

//Memoization
class Solution{
private:
    bool func(int index, vector<int> &arr, int n, int target, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return (target == arr[0]);

        if(dp[index][target] != -1)
            return dp[index][target];
        
        //Not pick
        bool notPick = func(index - 1, arr, n, target,dp);

        //Pick 
        bool pick = false;
        if(arr[index] <= target)
            pick = func(index - 1, arr, n, target - arr[index],dp);

        return dp[index][target] = (pick || notPick);
    }
public:
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for(auto i : arr)
            sum += i;
        
        if(sum%2)
            return false;
        
        vector<vector<int>> dp(n, vector<int>(sum + 1,-1));
        return func(n - 1,arr,n,sum/2,dp);
    }
};

//Tabulation
class Solution{
public:
    bool equalPartition(int n, vector<int> arr) {
        int target = 0;
        for(auto i : arr)
            target += i;
        
        if(target%2)
            return false;

        vector<vector<bool>> dp(n, vector<bool>(target + 1,0));

        for(int i = 0;i <n;i++)
            dp[i][0] = true;
        
        if(arr[0] <= target)
            dp[0][arr[0]] = true;
        
        int sum = target;

        for(int index = 1; index < n;index++)
        {
            for(int target = 0; target <= sum; target++)
            {   
                //Not pick
                bool notPick = dp[index - 1][target];

                //Pick 
                bool pick = false;
                if(arr[index] <= target)
                    pick = dp[index - 1][target - arr[index]];

                dp[index][target] = (pick || notPick);
            }
        }
        
        
        return dp[n-1][sum/2];
    }
};

//Space optimization
class Solution{
public:
    bool equalPartition(int n, vector<int> arr) {
        int target = 0;
        for(auto i : arr)
            target += i;
        
        if(target%2)
            return false;

        vector<bool> prev(target + 1,0), curr(target + 1,0);

        prev[0] = true;
        curr[0] = true;

        prev[arr[0]] = true;
        
        int sum = target;

        for(int index = 1; index < n;index++)
        {
            for(int target = 0; target <= sum; target++)
            {   
                //Not pick
                bool notPick = prev[target];

                //Pick 
                bool pick = false;
                if(arr[index] <= target)
                    pick = prev[target - arr[index]];

                curr[target] = (pick || notPick);
            }
            prev = curr;
        }
        return prev[sum/2];
    }
};
