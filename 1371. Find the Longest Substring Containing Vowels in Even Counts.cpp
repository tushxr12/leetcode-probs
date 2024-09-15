class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a'  || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    int findTheLongestSubstring(string s) {
        map<int,int> mpp;
        mpp[0] = -1;
        int cnt = 0, ans = 0;
        for(int i = 0;i < s.size();i++)
        {
            if(isVowel(s[i]))
            {
                cnt ^= (1 << ((int)(s[i] - 'a')));
            }
            if(mpp.find(cnt) != mpp.end())
            {
                ans = max(ans, i - mpp[cnt]);
            }
            else
            {
                mpp[cnt] = i;
            }
        }
        return ans;
    }
};