//Recursion
class Solution
{
   private:
   int func(int index, int weight, vector<int> &wt, vector<int> &val)
   {
        if(index == 0)
        {
            if(wt[0] <= weight)
                return val[0];
            else
                return 0;
        }

        //Not take 
        int notTake = 0 + func(index - 1, weight, wt, val);

        //Take 
        int take = INT_MIN;
        if(weight >= wt[index])
        {
            take = val[index] + func(index - 1, weight - wt[index], wt, val);
        }

        return max(take, notTake);
   }


   public:
   int knapsack01(vector<int>& wt, vector<int>& val, int n, int W) 
   {
        return func(n -1, W, wt, val);
   }

};
