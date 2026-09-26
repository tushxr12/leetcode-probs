class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        
        unordered_map<string, string> mpp;
        for(auto &vec : knowledge)
        {
            mpp[vec[0]] = vec[1];
        }

        string ans = "";
        int i = 0;

        while(i < n)
        {
            if(s[i] == '('){
                int j = s.find(")", i + 1);
                string temp = s.substr(i+1, j - i - 1);
                ans += mpp.count(temp) ? mpp[temp] : "?";
                i = j;
            }
            else
            {
                ans.push_back(s[i]);
            }
            i++;
        }
        return ans;
    }
};
