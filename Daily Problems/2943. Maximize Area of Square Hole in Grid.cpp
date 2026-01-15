class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxConsHBars = 1, maxConsVBars = 1;
        int currConsHBars = 1, currConsVBars = 1;

        for(int i = 1;i < hBars.size();i++)
        {
            if(hBars[i] - hBars[i-1] == 1)
                currConsHBars += 1;
            else
                currConsHBars = 1;
            maxConsHBars = max(maxConsHBars, currConsHBars);
        }

        for(int i = 1;i < vBars.size();i++)
        {
            if(vBars[i] - vBars[i-1] == 1)
                currConsVBars += 1;
            else
                currConsVBars = 1;
            maxConsVBars = max(maxConsVBars, currConsVBars);
        }

        int minSide = min(maxConsVBars, maxConsHBars) + 1;
        return (minSide * minSide);
    }
};
