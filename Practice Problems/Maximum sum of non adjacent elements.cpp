//Recursion
//TC->O(2^N)
//SC->O(N)
class Solution {
private:
    int func(int index, vector<int> &nums)
    {
        if(index == 0)
        {
            return nums[0];
        }

        //Pick 
        int sum1 = INT_MIN;
        
        if(index > 1)
            sum1 = max(sum1, nums[index] + func(index - 2, nums));

        //Not Pick
        int sum2 = func(index - 1, nums);
        return max(sum1, sum2);
    }
public:
    int nonAdjacent(vector<int>& nums) {
        int n = nums.size();
        return func(n - 1, nums);
    }
};
