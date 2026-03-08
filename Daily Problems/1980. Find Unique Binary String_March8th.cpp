class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            char ch = nums[i][i] == '0' ? '1' : '0';
            ans += ch;
        }
        return ans;
    }
};
