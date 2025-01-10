class Solution {
private:
    vector<int> getFreq(string word)
    {
        vector<int> freq(26, 0);
        for(int i = 0;i < word.size();i++)
            freq[word[i] - 'a']++;
        return freq;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26, 0);
        vector<string> ans;
        for(auto i : words2)
        {
            vector<int> temp = getFreq(i);
            for(int j = 0;j < 26;j++)
                freq[j] = max(freq[j], temp[j]);
        }

        for(auto word : words1)
        {
            vector<int> temp = getFreq(word);
            bool flag = true;
            for(int j = 0;j < 26;j++)
            {
                if(freq[j] > temp[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(word);
        }
        return ans;
    }
};
