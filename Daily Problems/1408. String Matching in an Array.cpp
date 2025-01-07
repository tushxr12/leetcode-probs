class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // vector<string> ans;
        int n = words.size();
        set<string> st;
        for(int i = 0;i < n;i++)
        {
            string currWord = words[i];
            for(int j = 0;j < n;j++)
            {
                if(i != j)
                {
                    if(words[j].find(currWord) != string::npos)
                    {
                        st.insert(currWord);
                    }
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};
