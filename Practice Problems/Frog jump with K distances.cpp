//Recursion
//TC->O(K^N)
//SC->O(N)
class Solution {
private:
    int func(int ind, vector<int> &heights, int k)
    {
        if(ind == 0)
            return 0;
        
        int minSteps = INT_MAX;

        for(int j = 1;j <= k;j++)
        {
            if((ind - j) >=0 )
            {
                int jump = func(ind - j, heights, k) + abs(heights[ind] - heights[ind - j]);

                minSteps = min(minSteps, jump);
            }
        }
        return minSteps;
    }
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        return func(n - 1, heights, k);
    }
};
