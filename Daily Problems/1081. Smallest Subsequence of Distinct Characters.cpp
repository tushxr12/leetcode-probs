class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        string ans;
        vector<bool> taken(26, false);
        vector<int> lastIndex(26);

        for(int i = 0;i < n;i++)
        {
            lastIndex[s[i]-'a'] = i;
        }

        for(int i = 0;i < n;i++)
        {
            char ch = s[i];

            int index = ch - 'a';

            if(taken[index])
            {
                continue;
            }

            while(ans.size() > 0 && ans.back() > ch && lastIndex[ans.back() - 'a'] > i)
            {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(ch);
            taken[index] = true;
        }
        return ans;
    }
};
