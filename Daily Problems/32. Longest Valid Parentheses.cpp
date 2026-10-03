class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int n = s.size();
        int open = 0, close = 0;

        // Left to Right
        for(int i = 0;i < n;i++){
            if(s[i] == '(')
                open++;
            else
                close++;
            
            if(open == close)
                ans = max(ans, open + close);
            else if(close > open)
                open = close = 0;
        }

        // Righ to Left
        open = close = 0;

        for(int i = n - 1;i >= 0;i--){
            if(s[i] == ')')
                close++;
            else 
                open++;
            
            if(open == close)
                ans = max(ans, open + close);
            else if(open > close)
                open = close = 0;
        }
        return ans;
    }
};
