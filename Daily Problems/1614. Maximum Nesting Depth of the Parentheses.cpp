class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int ans = 0;
        int curr = 0;
        for(auto i : s)
        {
            if(i == '(')
                curr++;
            else if (i== ')')
                curr--;
            
            ans = max(ans, curr);
        }
        return ans;
    }
};
