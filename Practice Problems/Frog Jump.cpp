//Recursion
//TC->O(2^N)
//SC->O(N)
class Solution {
private:
    int f(int ind, vector<int> &heights)
    {
        if(ind == 0)
            return 0;
        
        int poss1 = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
        int poss2 = INT_MAX;

        if(ind > 1)
            poss2 = min(poss2,f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]));

        return min(poss1, poss2);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        return f(n - 1, heights);
    }
};
