//Recursion
class Solution{
private:
    int f(int index, int buy, vector<int> &arr,int n)
    {
        if(index == n)
            return 0;
        
        long profit = 0;

        if(buy)
        {
            profit = max(-arr[index] + f(index + 1,0,arr,n) , f(index + 1,1,arr,n));
        }
        else
        {
            profit = max(arr[index] + f(index + 1,1,arr,n), f(index+1,0,arr,n));
        }
        return profit;
        
    }
public:
    int stockBuySell(vector<int> arr, int n){
        return f(0, 1, arr, n);
    }
};

//Memoization
class Solution{
private:
    int f(int index, int buy, vector<int> &arr,int n, vector<vector<int>> &dp)
    {
        if(index == n)
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];
        long profit = 0;

        if(buy)
        {
            profit = max(-arr[index] + f(index + 1,0,arr,n,dp) , f(index + 1,1,arr,n,dp));
        }
        else
        {
            profit = max(arr[index] + f(index + 1,1,arr,n,dp), f(index+1,0,arr,n,dp));
        }
        return dp[index][buy] = profit;
        
    }
public:
    int stockBuySell(vector<int> arr, int n){
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0, 1, arr, n, dp);
    }
};

