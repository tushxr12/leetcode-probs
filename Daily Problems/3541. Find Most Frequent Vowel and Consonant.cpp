class Solution {
private:
    bool isVowel(char c)
    {
        string s = "aeiou";
        return (s.find(c) != string::npos);
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(char i : s)
            mpp[i]++;
        
        int vowelMaxFreq = 0, consonantMaxFreq = 0;

        for(auto i : mpp)
        {
            if(isVowel(i.first)){
                vowelMaxFreq = max(vowelMaxFreq, i.second);
            }
            else
            {
                consonantMaxFreq = max(consonantMaxFreq, i.second);
            }
        }

        return (vowelMaxFreq + consonantMaxFreq);
    }
};
