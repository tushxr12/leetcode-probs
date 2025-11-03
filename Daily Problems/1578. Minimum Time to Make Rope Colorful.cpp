class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int prevMax = 0;

        for(int i = 0;i < n;i++){
            if(i>0 && colors[i] != colors[i - 1])
                prevMax = 0;
            int curr = neededTime[i];
            ans += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }
        return ans;
    }
};
