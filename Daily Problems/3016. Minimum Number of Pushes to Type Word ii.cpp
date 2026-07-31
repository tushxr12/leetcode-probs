class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mpp(26,0);

        for(char &ch : word)
        {
            mpp[ch-'a']++;
        }

        sort(begin(mpp), end(mpp), greater<int>());
        int ans = 0;

        for(int i = 0;i < 26;i++)
        {
            int freq = mpp[i];
            int press = (i/8) + 1;
            ans += (freq*press);
        }
        return ans;
    }
};
