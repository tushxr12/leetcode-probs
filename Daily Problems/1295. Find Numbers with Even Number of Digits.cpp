class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(auto i : nums)
        {
            string numToString = to_string(i);
            if(numToString.size()%2 == 0)
                ans++;
        }
        return ans;
    }
};
