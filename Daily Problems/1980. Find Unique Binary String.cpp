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

//Better
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
