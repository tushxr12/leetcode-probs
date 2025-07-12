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
