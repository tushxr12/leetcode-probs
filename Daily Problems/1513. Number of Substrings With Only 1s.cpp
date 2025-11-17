class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        int n = s.size();
        int ans = 0, cnt= 0;

        for(int i = 0;i < n;i++){
            if(s[i] == '1')
            {
                cnt++;
                ans = (ans + cnt)%mod;
            }
            else
            {
                cnt = 0;
            }
        }

        return ans;
    }
};
