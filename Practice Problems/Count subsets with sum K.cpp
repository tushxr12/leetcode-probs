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
