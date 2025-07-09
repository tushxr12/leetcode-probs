//Recursion
class Solution{   
private:
    bool func(int index, int currSum, vector<int> &arr, int target)
    {
        if(currSum == target)
        {
            return true;
        }

        if(index == 0)
        {
            currSum += arr[index];
            return (currSum == target);
        }

        //Take
        currSum += arr[index];
        bool take = func(index - 1, currSum, arr, target);
        currSum -= arr[index];

        //Not take
        bool notTake = func(index - 1, currSum, arr, target);

        return (take || notTake);
    }
public:
    bool isSubsetSum(vector<int>arr, int target){
        int n = arr.size();
        return func(n - 1,0,arr,target);
    }
};
