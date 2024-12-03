class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int spIndex = 0;
        for(int i = 0;i < s.size();i++)
        {
            if(spIndex < spaces.size() && i == spaces[spIndex])
            {
                ans += ' ';
                spIndex++;
            }
            ans += s[i];
        }
        return ans;
    }
};
