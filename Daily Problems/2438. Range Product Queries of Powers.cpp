// TC -> O(Q*32)
// SC -> O(Q) -> Reuquired to return the ans
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<int> powers;

        for(int i = 0;i < 31;i++)
        {
            if((n & (1 << i)) != 0){
                powers.push_back(1 << i);
            }
        }

        for(auto i : powers)
            cout<<i<<" ";
        
        vector<int> ans;
        for(auto i : queries)
        {
            auto left = i[0];
            auto right = i[1];
            long long prod = 1;

            // Below loop can only run for 32 times in worst case
            for(int j = left;j <= right;j++)
            {
                prod = ((prod*powers[j])%mod);
            }
            ans.push_back(prod);
        }
        return ans;
    }
};
