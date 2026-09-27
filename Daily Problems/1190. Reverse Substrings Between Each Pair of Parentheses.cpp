class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        string ans;

        for(char &ch : s)
        {
            if(ch == '('){
                st.push(ans.size());
            }
            else if(ch == ')')
            {
                int lastLength = st.top();
                st.pop();
                reverse(ans.begin() + lastLength, ans.end());
            }
            else
            {
                ans += ch;
            }
        }
        return ans;
    }
};
