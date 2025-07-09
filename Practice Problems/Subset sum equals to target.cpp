//Recursion
class Solution{   
private:
    bool func(int index, int currSum, vector<int> &arr, int target)
    {
        if(currSum == target)
        {
            return true;
        }

        if(index == 0)
        {
            currSum += arr[index];
            return (currSum == target);
        }

        //Take
        currSum += arr[index];
        bool take = func(index - 1, currSum, arr, target);
        currSum -= arr[index];

        //Not take
        bool notTake = func(index - 1, currSum, arr, target);

        return (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return func(n - 1,0,arr,target);
    }
};

//Memoization
class Solution{   
private:
    bool func(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return target == arr[index];
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        //Not take 
        bool notTake = func(index - 1, arr, target, dp);

        //Take 
        bool take = false;
        if(arr[index] <= target)
        {
            take = func(index - 1, arr, target - arr[index], dp);
        }

        return dp[index][target] = (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1,-1));
        return func(n - 1,arr,target, dp);
    }
};
