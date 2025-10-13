class Solution {
private:
    bool isAnagram(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;

        sort(begin(s1), end(s1));
        sort(begin(s2), end(s2));

        return (s1 == s2);
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;

        ans.push_back(words[0]);

        for(int i = 1;i < n;i++){
            if(!isAnagram(words[i], ans.back()))
            {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
