class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> ans;
        ans.push_back(1);
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            digits[i] += 1;
            if (digits[i] != 10)
            {
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--)
            ans.push_back(digits[i]);

        return ans;
    }
};