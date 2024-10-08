class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(int i = 0;i < s.size();i++)
        {
            char ch = s[i];
            if(ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty() || st.top() == ']')
                {
                    st.push(ch);
                }
                else
                {
                    st.pop();
                }
            }
        }
        int brackets = st.size();
        int openBrackets = brackets/2;
        return (openBrackets + 1)/2;
    }
};
