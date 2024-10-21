class Solution {
private:
    int help(int i, string &s, unordered_set<string> &st, string temp)
    {
        if(i == s.size())
            return 0;
        else
        {
            int op1 = INT_MIN/2, op2 = INT_MIN/2;
            temp += s[i];
            if(st.find(temp) == st.end())
            {
                st.insert(temp);
                op1 = 1 + help(i + 1, s, st, "");
                st.erase(temp);
            }
            op2 = help(i + 1, s, st, temp);
            return max(op1, op2);
        }
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return help(0, s, st, "");
    }
};
