class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int aCount = 0, bCount = 0;

        for(int i = 0;i < n;i++)
        {
            if(s[i] == 'b')
                bCount+=1;
            
            if(s[i] == 'a')
            {
                if(bCount > 0)
                    return false;
            }
        }

        return true;
    }
};
