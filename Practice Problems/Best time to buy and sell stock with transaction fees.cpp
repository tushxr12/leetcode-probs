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
