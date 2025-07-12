//Recursion (Brute force)
class Solution{
    private:
    int func(int index, int currSum, vector<int> &arr, int k)
    {
        if(currSum == k)
            return 1;

        if(currSum > k)
            return 0;
        
        if(index == 0)
        {
            if(currSum==k && arr[index] == 0)
                return 1;
            if(currSum + arr[0] == k)
                return 1;
            if(currSum == k)
                return 1;
            return 0;
        }
            
        
        //Not Take 
        int notTake = func(index - 1, currSum, arr, k);

        int take = 0;
        if(arr[index] <= k)
            take = func(index - 1, currSum + arr[index], arr, k);

        return (take + notTake);
    }
	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        return func(n - 1, 0, arr, K);
	}
};

//Recursion(Better and Simple)
class Solution{
    int mod = 1e9 + 7;

    private:
    int func(int index, int target, vector<int> &arr)
    {
        if(target == 0)
            return 1;
        
        if(index == 0)
            return (target == arr[0]) ? 1 : 0;
        
        int notTake = func(index - 1, target, arr);

        int take = 0;
        if(arr[index] <= target)
            take = func(index - 1, target - arr[index], arr);
        
        return (take + notTake) % mod;
    }

	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        return func(n - 1, K, arr);
	}
};

//Memoization
class Solution{
    int mod = 1e9 + 7;

    private:
    int func(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(target == 0)
            return 1;
        
        if(index == 0)
            return (target == arr[0]) ? 1 : 0;
        
        if(dp[index][target] != -1)
            return dp[index][target];
        
        int notTake = func(index - 1, target, arr, dp);

        int take = 0;
        if(arr[index] <= target)
            take = func(index - 1, target - arr[index], arr, dp);
        
        return dp[index][target] = (take + notTake) % mod;
    }

	public:
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n , vector<int>(K + 1, -1));
        return func(n - 1, K, arr, dp);
	}
};

//Tabulation
class Solution{
    int mod = 1e9 + 7;
	public:
	int perfectSum(vector<int>&arr, int K){
		int n = arr.size();
		vector<vector<int>> dp(n , vector<int>(K + 1, 0));
		
		for(int i = 0;i < n;i++)
		    dp[i][0] = 1;
		
		if(arr[0] <= K)
		    dp[0][arr[0]] = 1;
		
		for(int index = 1; index < n;index++)
		{
		    for(int target = 1; target <= K;target++)
		    {
			int notTake = dp[index - 1][target];
		
			int take = 0;
			if(arr[index] <= target)
			    take = (dp[index - 1][target - arr[index]])%mod;
			
			dp[index][target] = (take + notTake) % mod;
		    }
		}
		return dp[n-1][K];
	}
};
