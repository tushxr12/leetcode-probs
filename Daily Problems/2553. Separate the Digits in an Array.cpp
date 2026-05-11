class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto &num : nums){
            vector<int> digits;
            while(num > 0){
                int ld = num % 10;
                digits.push_back(ld);
                num /= 10;
            }
            for(int i = digits.size() -1 ;i >=0;i--)
                ans.push_back(digits[i]);
        }
        return ans;
    }
};
