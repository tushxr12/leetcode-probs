class Solution {
public:
    string makeFancyString(string s) {
        char prev = s[0];
        int n = s.size();
        string ans = "";
        int freq = 1;
        ans += s[0];

        if(s.size() < 3)
            return s;
        
        for(int i = 1;i < n;i++)
        {
            if(s[i] == prev)
                freq++;
            else
            {
                prev = s[i];
                freq = 1;
            }

            if(freq < 3)
                ans += s[i];
        }
        return ans;
    }
};
