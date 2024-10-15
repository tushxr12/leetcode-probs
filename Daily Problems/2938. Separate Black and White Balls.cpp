class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        int cnt1 = 0;
        for(int i = 0;i < s.size();i++)
        {
            if(s[i] == '1')
                cnt1++;
            else
                steps += (cnt1);
        }
        return steps;
    }
};
