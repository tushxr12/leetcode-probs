class Solution {
private:
    set<string> st;
    bool backtrack(vector<string> &nums, string &curr, int n)
    {
        if(curr.size() >= n)
        {
            if(st.find(curr) == st.end())
                return true;
            return false;
        }

        for(char ch = '0' ; ch <= '1' ;ch++)
        {
            curr += ch;
            if(backtrack(nums, curr, n))
                return true;
            curr.pop_back();
        }
        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(auto i : nums)
            st.insert(i);
        string curr ="";
        backtrack(nums, curr, n);
        return curr;
    }
};
