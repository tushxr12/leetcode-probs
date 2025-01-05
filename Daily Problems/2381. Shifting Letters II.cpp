class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(auto i : shifts)
        {
            auto currShift = i; //[0,1,0]
            int startIndex = currShift[0], endIndex = currShift[1], direction = currShift[2];

            if(direction == 0)
            {
                for(int i = startIndex;i <= endIndex;i++)
                {
                    if(s[i] == 'a')
                        s[i] = 'z';
                    else
                        s[i]--;   
                }
            }
            else
            {
                for(int i = startIndex;i <= endIndex;i++)
                {
                    if(s[i] == 'z')
                        s[i] = 'a';
                    else
                        s[i]++;   
                }
            }
        }
        return s;
    }
};
