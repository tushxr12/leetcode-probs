class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size(), cnt = 0;
        map<char,int> mpp;
        for(int i = 0;i <n;i++)
        {
            mpp[s1[i]]++;
            if(s1[i] != s2[i])
                cnt++;
        }
        for(auto i : s2)
            if(mpp.find(i) == mpp.end())
                return false;
            else
            {
                int cntS1 = mpp[i];
                int cntS2 = count(s2.begin(), s2.end(), i);
                if(cntS1 != cntS2)
                    return false;
            }
        if(n <= 2)
        {
            return (s1 == s2);
        }
        return (cnt <= 2);
    }
};
