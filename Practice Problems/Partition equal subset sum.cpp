//Recursion
class Solution{
private:
    bool func(int index, vector<int> &arr, int n, int target)
    {
        if(target == 0)
            return true;
        
        if(index == 0)
            return (target == arr[0]);
        
        //Not pick
        bool notPick = func(index - 1, arr, n, target);

        //Pick 
        bool pick = false;
        if(arr[index] <= target)
            pick = func(index - 1, arr, n, target - arr[index]);

        return (pick || notPick);
    }
public:
    bool equalPartition(int n, vector<int> arr) {
        int sum = 0;
        for(auto i : arr)
            sum += i;
        
        if(sum%2)
            return false;
        return func(n - 1,arr,n,sum/2);
    }
};
