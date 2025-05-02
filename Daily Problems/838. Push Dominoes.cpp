class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        vector<int> rightClosestL(n);
        vector<int> leftClosestR(n);

        //Move from left to right
        for(int i = 0;i < n;i++)
        {
            if(dominoes[i] == 'R')
            {
                leftClosestR[i] = i;
            }
            else if(dominoes[i] == '.')
            {
                leftClosestR[i] = i > 0 ? leftClosestR[i - 1] : -1;
            }
            else
            {
                leftClosestR[i] = -1;
            }
        }


        //Move from right to left
        for(int i = n - 1;i >= 0;i--)
        {
            if(dominoes[i] == 'L')
            {
                rightClosestL[i] = i;
            }
            else if(dominoes[i] == '.')
            {
                rightClosestL[i] = (i + 1) < n ? rightClosestL[i + 1] : -1;
            }
            else
            {
                rightClosestL[i] = -1;
            }
        }

        string ans(n, ' ');
        for(int i = 0;i < n;i++)
        {
            int disRightL = abs(i - rightClosestL[i]);
            int disLeftR = abs(i - leftClosestR[i]);

            if(leftClosestR[i] == rightClosestL[i])
            {
                ans[i] = '.';
            }
            else if(rightClosestL[i] == -1)
            {
                ans[i] = 'R';
            }
            else if(leftClosestR[i] == -1)
            {
                ans[i] = 'L';
            }
            else if(disRightL == disLeftR)
            {
                ans[i] = '.';
            }
            else
            {
                ans[i] = (disRightL > disLeftR) ? 'R' : 'L';
            }
        }
        return ans;

    }
};
