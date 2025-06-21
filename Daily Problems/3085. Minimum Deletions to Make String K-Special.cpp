class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);

        for(auto ch : word)
            freq[ch - 'a']++;
        
        int res = word.size();

        for(int i = 0;i < 26;i++)
        {
            int del = 0;
            for(int j = 0;j < 26;j++)
            {
                if(i == j)
                    continue;
                
                if(freq[i] > freq[j])
                    del += freq[j];
                else if(abs(freq[j] - freq[i]) > k)
                    del += (abs(freq[j] - freq[i] - k));
            }
            res = min(res, del);
        }

        return res;
    }
};
