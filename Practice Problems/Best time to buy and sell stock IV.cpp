//Recursion

class Solution{
private:
    int func(int index, vector<int> &arr, int n,int buy, int cap)
    {
        if(index >= n || cap == 0)
            return 0;
        
        if(buy)
        {
            return max(-arr[index] + func(index + 1,arr,n,0,cap), 0 + func(index + 1,arr,n,1,cap));
        }
        else
        {
            return max(arr[index] + func(index + 1,arr,n,1,cap - 1), func(index + 1, arr, n, 0, cap));
        }
    }
public:
    int stockBuySell(vector<int> arr, int n, int k){
        return func(0,arr,n,1,k);
    }
};

//Memoization
class Solution{
private:
    int func(int index, vector<int> &arr, int n,int buy, int cap, vector<vector<vector<int>>> &dp)
    {
        if(index >= n || cap == 0)
            return 0;
        
        if(dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        int profit = 0;
        if(buy)
        {
             profit = max(-arr[index] + func(index + 1,arr,n,0,cap, dp), 0 + func(index + 1,arr,n,1,cap, dp));
        }
        else
        {
             profit = max(arr[index] + func(index + 1,arr,n,1,cap - 1, dp), func(index + 1, arr, n, 0, cap, dp));
        }
        return dp[index][buy][cap] = profit;
    }
public:
    int stockBuySell(vector<int> arr, int n, int k){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return func(0,arr,n,1,k,dp);
    }
};
