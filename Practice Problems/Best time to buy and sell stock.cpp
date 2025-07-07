class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int maxProfit = 0;
        int mini = arr[0];

        for(int i = 1;i < n;i++)
        {
            int currProfit = arr[i] - mini;
            maxProfit = max(maxProfit, currProfit);
            mini = min(mini, arr[i]);
        }
        return maxProfit;
    }
};

