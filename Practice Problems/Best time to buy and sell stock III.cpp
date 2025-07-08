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
    int stockBuySell(vector<int> arr, int n){
        return func(0, arr, n, 1, 2);
    }
};
