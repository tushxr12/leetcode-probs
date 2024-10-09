class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        for(auto i : s)
        {
            if(i == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.empty() || st.top() == ')')
                {
                    st.push(i);
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.size();
    }
};
