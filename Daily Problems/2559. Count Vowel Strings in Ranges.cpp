//Brute force
class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int k = 0;
        for(auto i : queries)
        {
            auto currQuery = i; // [0, 2]
            int startIndex = currQuery[0], endIndex = currQuery[1];
            int cnt = 0;
            for(int i = startIndex; i <= endIndex;i++)
            {
                string currWord = words[i];
                int currWordSize = currWord.size();
                if(isVowel(currWord[0]) && isVowel(currWord[currWordSize - 1]))
                {
                    cnt++;
                }
            }
            ans[k] = cnt;
            k++;
        }
        return ans;
    }
};
