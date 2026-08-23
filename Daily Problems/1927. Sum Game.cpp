class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQm = 0, rightQm = 0;

        for(int i = 0;i < n;i++)
        {
            if(num[i] == '?')
            {
                if(i < n/2)
                    leftQm++;
                else
                    rightQm++;
            }
            else
            {
                if(i < n/2)
                    leftSum+=num[i]-'0';
                else
                    rightSum+=num[i]-'0';
            }
        }

        int totalQms = leftQm + rightQm;
        if(totalQms%2)
            return true;
        
        int left = 2*leftSum + 9*leftQm;
        int right = 2*rightSum + 9*rightQm;

        if(left == right)
            return false;
        return true;
    }
};
