class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string ans = "";
        char maxChar = ' ';
        
        for(int i = 2;i < n;i++)
        {
            if(num[i] == num[i - 1] && num[i] == num[i - 2])
                maxChar = max(maxChar, num[i]);
        }

        if(maxChar == ' ')
            return "";
        for(int i = 0;i <=2;i++)
            ans += maxChar;
        return ans;
    }
};
