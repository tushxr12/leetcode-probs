class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto i : s)
        {
            if(i >= 'a' && i <= 'z')
            {
                st.push(i);
            }
            else
            {
                if(st.empty())
                    continue;
                else
                    st.pop();
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
