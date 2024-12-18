class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i = 0;i < prices.size();i++)
        {
            bool fl = false;
            if(i == prices.size() - 1)
            {
                ans.push_back(prices[i]);
                return ans;
            }
            for(int j = i + 1;j < prices.size();j++)
            {
                if(prices[j] <= prices[i])
                {
                    fl = true;
                    ans.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if(!fl)
            {
                ans.push_back(prices[i]);
            }
        }
        return ans;
    }
};
