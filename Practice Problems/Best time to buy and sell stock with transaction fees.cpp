//Recursion
class Solution{
private:
     int f(int index, int buy, vector<int> &arr,int n, int fee)
    {
        if(index == n)
            return 0;
        
        long profit = 0;

        if(buy)
        {
            profit = max(-arr[index] -fee + f(index + 1,0,arr,n,fee) , f(index + 1,1,arr,n,fee));
        }
        else
        {
            profit = max(arr[index] + f(index + 1,1,arr,n, fee), f(index+1,0,arr,n, fee));
        }
        return profit;
        
    }
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        return f(0, 1, arr, n, fee);
    }
};

//Memoization
class Solution{
private:
     int f(int index, int buy, vector<int> &arr,int n, int fee, vector<vector<int>> &dp)
    {
        if(index == n)
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        long profit = 0;

        if(buy)
        {
            profit = max(-arr[index] -fee + f(index + 1,0,arr,n,fee, dp) , f(index + 1,1,arr,n,fee, dp));
        }
        else
        {
            profit = max(arr[index] + f(index + 1,1,arr,n, fee, dp), f(index+1,0,arr,n, fee, dp));
        }
        return dp[index][buy] = profit;
        
    }
public:
    int stockBuySell(vector<int> arr, int n, int fee){
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return f(0, 1, arr, n, fee, dp);
    }
};
