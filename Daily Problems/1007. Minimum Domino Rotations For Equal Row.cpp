class Solution {
private:
    int find(vector<int>& tops, vector<int>& bottoms, int val)
    {
        int ans = -1;
        int n = tops.size(), topSwap = 0, bottomSwap = 0;

        for(int i = 0;i < n;i++)
        {
            if(tops[i] != val && bottoms[i] != val)
            {
                return -1;
            }
            else if(tops[i] != val)
            {
                topSwap++;
            }
            else if(bottoms[i] != val)
            {
                bottomSwap++;
            }
        }

        return (min(topSwap, bottomSwap));
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        int n  = tops.size();

        for(int i = 1;i <= 6;i++)
        {
            int steps = find(tops, bottoms, i);
            if(steps != -1)
                res = min(res, steps);
        }
        return res == INT_MAX ? -1 : res;
    }
};
