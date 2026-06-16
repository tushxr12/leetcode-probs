class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto &i : s)
        {
            if(i >= 'a' && i <= 'z')
            {
                res += i;
            }
            else if(i == '*')
            {
                if(res.size() != 0)
                    res.pop_back();
            }
            else if(i == '#')
            {
                res += res;
            }
            else if(i == '%')
            {
                reverse(begin(res), end(res));
            }
        }
        return res;
    }
};
