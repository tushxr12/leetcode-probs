class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for(auto i : rolls)
            sum += i;
        
        int remSum = (mean*(n + rolls.size())) - sum;
        if(remSum > 6 * n || remSum < n)
            return {};
        
        int divideEqually = remSum/n;
        int rem = remSum % n;

        vector<int> ans(n,divideEqually);
        for(int i = 0;i < rem;i++)
            ans[i]++;
        return ans;
    }
};