class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";
        for(auto &ch : s)
        {
            if(ch == '(')
            {  
                if(cnt != 0)
                    res.push_back(ch);
                cnt++;
            }
            else
            {
                cnt--;
                if(cnt != 0)
                    res.push_back(ch);
            }
        }
        return res;
    }
};
